# Linux Shell Study  

- [Linux Shell Study](#linux-shell-study)
  - [if 조건문 연산](#if-조건문-연산)
    - [문자열](#문자열)
    - [산술](#산술)
    - [결합](#결합)
    - [-d : 파일이 디렉터리이면 true](#-d--파일이-디렉터리이면-true)
    - [-e : 파일이 존재하면 true](#-e--파일이-존재하면-true)
    - [-L : 파일이 심볼릭 링크이면 true](#-l--파일이-심볼릭-링크이면-true)
    - [-r : 파일이 읽기 가능하면 true](#-r--파일이-읽기-가능하면-true)
    - [-s : 파일 크기가 0보다 크면 true](#-s--파일-크기가-0보다-크면-true)
    - [-w : 파일이 쓰기 가능하면 true](#-w--파일이-쓰기-가능하면-true)
    - [-x : 파일이 실행 가능하면 true](#-x--파일이-실행-가능하면-true)
    - [-nt, -ot : 최신/이전 파일이면 true](#-nt--ot--최신이전-파일이면-true)
    - [-ef : 같은 파일이면 true](#-ef--같은-파일이면-true)

## if 조건문 연산  
### 문자열  
```shell
"str1" == "str2"
"str1" != "str2"
-z "str1"  # 문자열의 길이가 0이면 true
-n "str2"  # 문자열의 길이가 0이 아니면 true
```

### 산술  
```shell
if [[ 23 -eq 21 ]]; then echo "true"; else echo "false"; fi  # false : 두 값이 같으면 true
if [[ 23 -ne 21 ]]; then echo "true"; else echo "false"; fi  # true : 두 값이 다르면 true

if [[ 23 -gt 21 ]]; then echo "true"; else echo "false"; fi # true
if [[ 23 -gt 23 ]]; then echo "true"; else echo "false"; fi  # false
if [[ 23 -ge 23 ]]; then echo "true"; else echo "false"; fi  # true : val1 이 크거나 같으면 true
if [[ 13 -lt 23 ]]; then echo "true"; else echo "false"; fi  # true : val1 이 작으면 true
if [[ 13 -le 13 ]]; then echo "true"; else echo "false"; fi  # true : val1 이 작거나 같으면 true
```

### 결합  
```shell
if [ 1 -eq 1 ] && [ 2 -ne 3 ];then echo "true"; else echo "false"; fi  # true : AND
if [ 1 -eq 4 ] || [ 2 -ne 3 ];then echo "true"; else echo "false"; fi  # true : OR
```

### -d : 파일이 디렉터리이면 true
```shell
if [[ -d multiprocessing ]]; then echo "directory"; else echo "not directory"; fi  # directory
if [[ -d README.md ]]; then echo "directory"; else echo "not directory"; fi  # not directory
```

### -e : 파일이 존재하면 true  
```shell
if [[ -e README.md ]]; then echo "file exists"; else echo "not exists"; fi  # file exists
if [[ -e multiprocessing ]]; then echo "file exists"; else echo "not exists"; fi  # file exists
if [[ -e multiprocessing.txt ]]; then echo "file exists"; else echo "not exists"; fi  # not exists
if [[ -e .git ]]; then echo "file exists"; else echo "not exists"; fi  # file exists
```

### -L : 파일이 심볼릭 링크이면 true  
```shell
if [[ -L README.md ]]; then echo "symbolic link"; else echo "not symbolic"; fi  # not symbolic
```

### -r : 파일이 읽기 가능하면 true  
```shell
if [[ -r README.md ]]; then echo "readable"; else echo "not readable"; fi  # readable
if [[ -r .git ]]; then echo "readable"; else echo "not readable"; fi  # readable
```

### -s : 파일 크기가 0보다 크면 true
```shell
if [[ -s README.md ]]; then echo "file size > 0"; else echo "file size zero"; fi  # file size > 0
if [[ -s .git ]]; then echo "file size > 0"; else echo "file size zero"; fi  # file size > 0
touch tmp.txt && if [[ -s tmp.txt ]]; then echo "file size > 0"; else echo "file size zero"; fi && rm tmp.txt  # file size zero
```

### -w : 파일이 쓰기 가능하면 true  
```shell
if [[ -w README.md ]]; then echo "writable"; else echo "not writable"; fi  # writable
```

### -x : 파일이 실행 가능하면 true  
```shell
if [[ -x README.md ]]; then echo "executable"; else echo "not executable"; fi  # not executable
if [[ -x multiprocessing ]]; then echo "executable"; else echo "not executable"; fi  # executable
```

### -nt, -ot : 최신/이전 파일이면 true  
```shell
if [[ README.md -nt multiprocessing ]]; then echo "file1 is newer than file2"; else echo "file1 is not newer than file2"; fi  # file1 is newer than file2
if [[ README.md -ot multiprocessing ]]; then echo "file1 is newer than file2"; else echo "file1 is not newer than file2"; fi  # file1 is not newer than file2
```

### -ef : 같은 파일이면 true  
```shell
if [[ README.md -ef multiprocessing ]]; then echo "files are same"; else echo "files are different"; fi  # files are different
if [[ README.md -ef README.md ]]; then echo "files are same"; else echo "files are different"; fi  # files are same
```
