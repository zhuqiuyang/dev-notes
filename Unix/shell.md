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
