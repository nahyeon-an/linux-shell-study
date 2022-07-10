#!/bin/bash

job_pool_end_of_jobs="END_OF_JOBS"
job_pool_job_queue="/tmp/job_queue_$$"
job_pool_result_log="/tmp/job_result_log_$$"
job_pool_echo_command=0
job_pool_size=-1  # 병렬잡 개수
job_pool_nerros=0  # exit with non-zero 개수

function _job_pool_echo() {
  if [[ "${job_pool_echo_command}" == "1" ]];
  then
    # 모든 입력 인자를 출력
    echo $@
  fi
}

function _job_pool_cleanup() {
  rm -f ${job_pool_job_queue} ${job_pool_result_log}
}

function _job_pool_exit_handler() {
  _job_pool_stop_workers
  _job_pool_cleanup
}

function _job_pool_print_result_log() {
  job_pool_nerros=$(grep ^ERROR "${job_pool_result_log}" | wc -l)
  cat "${job_pool_result_log}" | sed -e 's/^ERROR//'
}

function _job_pool_worker() {
  local id=$1
  local job_queue=$2
  local result_log=$3
  local cmd=
  local args=

  # open "job_queue" for reading and writing on fd 7
  exec 7<> ${job_queue}
  while [[ "${cmd}" != "${job_pool_end_of_jobs}" && -e "${job_queue}" ]];
  do
    # get an exclusive lock on fd 7
    flock --exclusive 7
    IFS=$'\v'
    echo ${IFS}
    read cmd args <${job_queue}
    set -- ${args}
    unset IFS
    flock --unlock 7

    if [[ "${cmd}" == "${job_pool_end_of_jobs}" ]];
    then
      # end of job flag
      # other siblings know that end
      echo "${cmd}" >&7
    else
      _job_pool_echo "### _job_pool_worker-${id}: ${cmd}"
      # 다른 프로세스 실행
      { ${cmd} "$@" ; }
      # exit code 확인 
      local result=$?
      local status=
      if [[ "${result}" != "0" ]];
      then
        status=ERROR
      fi
      # error 를 로그에 쓴다
      exec 8<> ${result_log}
      flock --exclusive 8
      _job_pool_echo "${status}job_pool: exited ${result}: ${cmd} $@" >> ${result_log}
      flock --unlock 8
      exec 8>&-
      _job_pool_echo "### _job_pool_worker-${id}: exited ${result}: ${cmd} $@"
    fi
  done
  exec 7>&-
}

function _job_pool_stop_worker() {
  echo ${job_pool_end_of_jobs} >> ${job_pool_job_queue}
  wait
}

function _job_pool_start_workers() {
  local job_queue=$1
  local result_log=$2
  for ((i=0; i<${job_pool_size}; i++));
  do
    _job_pool_worker ${i} ${job_queue} ${result_log} &
  done
}

function job_pool_init() {
  local pool_size=$1
  local echo_command=$2

  # global attr 셋팅
  job_pool_size=${pool_size:=1}
  job_pool_echo_command=${echo_command:=0}

  rm -rf ${job_pool_job_queue} ${job_pool_result_log}
  # fifo job queue
  mkfifo ${job_pool_job_queue}
  # exit code log
  touch ${job_pool_result_log}

  _job_pool_start_workers ${job_pool_job_queue} ${job_pool_result_log}
}

function job_pool_shutdown() {
  _job_pool_stop_workers
  _job_pool_print_result_log
  _job_pool_cleanup
}

function job_pool_run() {
  if [[ "${job_pool_size}" == "-1" ]];
  then
    job_pool_init
  fi
  printf "%s\v" "$@" >> ${job_pool_job_queue}
  echo >> ${job_pool_job_queue}
}

function job_pool_wait() {
  _job_pool_stop_workers
  _job_pool_start_workers ${job_pool_job_queue} ${job_pool_result_log}
}