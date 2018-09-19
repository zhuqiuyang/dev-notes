### 重定向

/dev/null ：代表空设备文件

> ：代表重定向到哪里，例如：echo "123" > /home/123.txt

- 0 表示标准输入
- 1 表示 stdout 标准输出，系统默认值是 1，所以">/dev/null"等同于"1>/dev/null"
- 2 表示 stderr 标准错误
- `&`表示等同于的意思，`2>&1`，表示 2 的输出重定向等同于 1
- `&>file` 标准输出 和 标准错误输出 都重定向到文件 file 中

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

- `s` 命令:
  - `sed 's/line/text/g' test.txt` 将所有行的 `line` 替换为 `text`,`g` 代表全局选项，没有 `g` 只替换所有行的第一个匹配项

### awk

> 由三位发明者首字母命名
>
> http://awk.readthedocs.io/en/latest/chapter-one.html

- AWK 程序是由一系列模式--动作对组成的，写做

```sh
pattern { action }
```

#### 使用

> 现在你想打印出工作时间超过零小时的员工的姓名和工资（薪资乘以时间）

```sh
# cd awk
awk '$3 >0 { print $1, $2 * $3 }' emp.data
```

- 打印多个 file: `awk 'program' input files`
- 省略 file 将从终端接收数据, 直到(Ctrl-D): `awk '$3 == 0 { print $1 }'`
- `NF`(字段数量), 可用于输入最后一个字段内容: `{ print NF, $1, $NF }`
- `NR`(行号)
- 内置函数
  - `length()`: 计算字符串长度

### set -e

- `-e`: 若指令传回值不等于 0，则立即退出 shell.

### shift

> 删除一个入参, $1 从此不是最初的 $1

`$@` 显示当前所有参数.

### dirname

获取文件夹名:

```sh
dirname foo/bar/baz
foo/bar
```

### 字符串

- `/`: 匹配第一个
- `//`: 匹配所有
- `/#`: 匹配开头
- `/`: 匹配末尾

```sh
$ foo=JPG.JPG
$ echo ${foo/JPG/jpg}
jpg.JPG
$ echo ${foo//JPG/jpg}
jpg.jpg
$ echo ${foo/#JPG/jpg}
jpg.JPG
$ echo ${foo/%JPG/jpg}
JPG.jpg
```

### 系统资源

```sh
# 每个核的负载
mpstat -P ALL 5
```

### 工作遇到

- `declare`: 声明变量
- `exit 0`: 正常退出

#### 端口占用查看

```sh
lsof -i:端口号
```
