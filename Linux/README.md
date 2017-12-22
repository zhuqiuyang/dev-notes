### 重定向
/dev/null ：代表空设备文件
>  ：代表重定向到哪里，例如：echo "123" > /home/123.txt
- 0表示标准输入
- 1表示stdout标准输出，系统默认值是1，所以">/dev/null"等同于"1>/dev/null"
- 2表示stderr标准错误
- `&`表示等同于的意思，`2>&1`，表示2的输出重定向等同于1
- `&>file` 标准输出 和 标准错误输出 都重定向到文件file中

### FOR
```sh
#!/bin/bash

ARR=("1" "2" "3")

for i in ${ARR[@]}
do
  echo $i;
done
```