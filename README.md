# Linux Shell Study  

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

```