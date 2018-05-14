### 重定向

/dev/null ：代表空设备文件

> ：代表重定向到哪里，例如：echo "123" > /home/123.txt

* 0 表示标准输入
* 1 表示 stdout 标准输出，系统默认值是 1，所以">/dev/null"等同于"1>/dev/null"
* 2 表示 stderr 标准错误
* `&`表示等同于的意思，`2>&1`，表示 2 的输出重定向等同于 1
* `&>file` 标准输出 和 标准错误输出 都重定向到文件 file 中

### FOR

```sh
#!/bin/bash

ARR=("1" "2" "3")

for i in ${ARR[@]}
do
  echo $i;
done
```

### ipconfig

> interface config

### sed

> stream editor: https://qianngchn.github.io/wiki/4.html

* `s` 命令:
  * `sed 's/line/text/g' test.txt` 将所有行的 `line` 替换为 `text`,`g` 代表全局选项，没有 `g` 只替换所有行的第一个匹配项
