#!/bin/bash

. job_pool.sh

function run_job_pool() {
  echo "Hello Job Pool $$"
}

job_pool_init 3 0

job_pool_run run_job_pool
job_pool_run sleep 3
job_pool_run run_job_pool
job_pool_run run_job_pool
job_pool_run sleep 3
job_pool_run run_job_pool
job_pool_run sleep 3

job_pool_wait

job_pool_shutdown

echo "job_pool_nerrors: ${job_pool_nerrors}"