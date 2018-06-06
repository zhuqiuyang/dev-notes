# Bash

> man bash: 阅读手册

- 重定向: cat(连接文件), wc(打印行号), `grep`(打印匹配行), tail(末尾读), `tee`(复制流)
  > http://billie66.github.io/TLCL/book/chap07.html
- 文件: find, xargs
  > http://billie66.github.io/TLCL/book/chap18.html
- 文本处理: cut , `sed`
  > http://billie66.github.io/TLCL/book/chap21.html
- 格式化输出:
  > http://billie66.github.io/TLCL/book/chap22.html

## 重定向

### Tee

> https://linux.101hacks.com/unix/tee-command-examples/
>
> 复制 stdin 到 stdout

```sh
# 不会输出到屏幕
ls > file

# 也会输出到屏幕
$ ls | tee file

# Write the output to two commands(*)
crontab -l | tee crontab-backup.txt | sed 's/old/new/' | crontab –
```

## 文件

### xargs

> 参数分发->执行 cmd, eg: 10 个参数, 每批 2 个, 4 个并行消费.

| Command | Description                    | Example |
| ------- | ------------------------------ | ------- |
| -I      | 参数所应该在管道后面命令的位置 |         |
| -n      | 单次消费参数数                 |         |
| -P      | 并发数                         |         |

与直接 pipe 的区别:

- pipe 直接提供了内容
- `xargs`是把内容提取, 作为参数, 再提供给 command

```sh
find . -name '*.yaml' | grep network
find . -name '*.yaml' | xargs grep network

# -I 调整了参数的位置
find . -name '*.yaml' | xargs -I {} grep network {}
```

## 文本处理

### Sed, a stream editor

- Sed Invoke: `sed SCRIPT INPUTFILE...`

- 如果输入是`-`(或者没有指定 FILE), sed filter 会从`stdin`读取 content, 如下 cmd 是相同的

```sh
sed 's/hello/world/' input.txt > output.txt
sed 's/hello/world/' < input.txt > output.txt
cat input.txt | sed 's/hello/world/' - > output.txt
```

## 参考

- http://billie66.github.io/TLCL/book/chap21.html
- http://www.grymoire.com/Unix/Sed.html
- https://www.gnu.org/software/sed/manual/sed.html#Introduction
