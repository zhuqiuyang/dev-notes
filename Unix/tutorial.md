## Shell Scripting Tutorial

> https://www.shellscript.sh/

### 2. Philosophy

sh 给许多 UNIX admin 不良的印象, 由于两点:

* speed 不如 C, 甚至 Perl
* 有很多低质量的 shell script

写出 good, clean, quick, shell scripts, 需:

* The most important criteria must be a clear, readable layout.

* 避免不必要的`command`

A clear layout 可以使 shell script 变得更易于理解, 而非"黑魔法"(晦涩). 记住两点:

1.  First, a simple script will, more often than anticipated, grow into a large, complex one.
2.  如果没人理解, 将由你持续维护.

```sh
cat /tmpmp/myfile yfile | grep "mystring"mystring"

# 改写成如下, 更高效
grep "mystring" /tmp/myfile
```

* 节省了`cat`excutable 的定位和加载
* 没有 pipe 的建立和释放

### 3. A First Script

```sh
#!/bin/sh
# This is a comment!
echo Hello World        # This is a comment, too!
```

* `#!`是一个特殊的指令, 告诉 UNIX 这个 script 的解析器.

```sh
echo Hello    World
#上面等同于
echo Hello World

echo "Hello      World"
```

因为 shell 会先解析`argument`, 再传给 command.

* 多个参数之间的空格会被`忽略`
* `quote` 内的内容会被当成一个参数, 会被原封不动的传给 command

看`frist2.sh`例子内容.

### 4. Variables - Part I

"=" sign 之间不可以有空格: `VAR=value` works

* 一个包含`空格`的 string 必须用`"`包裹起来(shell knows to treat it all as one), 否则`MY_MESSAGE=Hello World`会执行 command`World`after assigning`MY_MESSAGE=Hello`
* 所有变量都被存储成`strings`

通过`read`command, 我们可以通过交互方式定义 variable:

> var2.sh

```sh
#!/bin/sh
echo What is your name?
read MY_NAME
echo "Hello $MY_NAME - hope you're well."
```

#### Scope of Variables

export, source

* `export` 会在当前 shell 的环境中添加
* `source` 会使

shell 有时不知道`变量`的起始点, 需要通过`curly`手动指定, 如下:

> user.sh

```sh
#!/bin/sh
echo "What is your name?"
read USER_NAME
echo "Hello $USER_NAME"
echo "I will create you a file called ${USER_NAME}_file"
touch "${USER_NAME}_file"
```

* `"${USER_NAME}_file"`使用`"`包括, 是因为假如用户输入了`Steven Parker`, 会执行成`touch Steve Parker_file`, 创建`Steve`he `Parker_file`两个文件. `"`避免了这个问题的发生.

### 6. Escape Characters

大部分字母, 例如`*`, `'`不会被 interpreted, 当置于 double quotes 中时.

```sh
$ echo *
case.shtml escape.shtml first.shtml
functions.shtml hints.shtml index.shtml
ip-primer.txt raid1+0.txt
$ echo *txt
ip-primer.txt raid1+0.txt
```

* In the first example, \* is expanded to mean all files in the current directory.
* In the second example, \*txt means all files ending in txt.

`"`, `$`, \`, and `\` 仍会被 shell interpreted, 即使置于 double quotes 中.

* The backslash (\\) character is used to mark 特殊字符

```sh
$ echo "A quote is \", backslash is \\, backtick is \`."
A quote is ", backslash is \, backtick is `.
$ echo "A few spaces are    ; dollar is \$. \$X is ${X}."
A few spaces are    ; dollar is $. $X is 5.
```

* Dollar ($) is special because it marks a variable

### 7. Loops

在 Bourne shell 中, 我们拥有`for` and `while` loops

#### For Loop

`for` loops iterate through a set of values until the list is exhausted:

> 下面 script, 值得  尝试, `*`会匹配文件夹中的所有 file

```sh
for i in hello 1 * 2 goodbye
do
  echo "Looping ... i is set to $i"
done
```

#### While Loops

> The colon (:) always evaluates to true

```sh
#!/bin/sh
while :
do
  echo "Please type something in (^C to quit)"
  read INPUT_STRING
  echo "You typed: $INPUT_STRING"
done
```

--

一些有用的 bash

```sh
# 创建多个文件夹
mkdir rcdir rc{0,1,2,3,4,5,6,S}.d
# instead of the more cumbersome:

for runlevel in 0 1 2 3 4 5 6 S
do
  mkdir rc${runlevel}.d
done
```

### 10. Variable(Part 2)

* `$0`是`basename`of the program as it was called.
* `$1 .. $9`: 前 9 个参数
  * 通过`shift`获取更多的参数
* `$@`是所有的参数`$1 .. whatever`; `$*`同理, 但是不包含空格, 尽量使用前者.
* `$?`是一个特殊 variable, contains 上一个命令的`exit value`
* `$#`参数的数量

其他:

* `$$`: PID(进程 ID)
* `$!`: PID of the last run background process.
* `IFS`(Internal Field Separator), default is `SPACE TAB NEWLINE`

### 11. Variable(Part 3)

* `:=`用于设置默认值:

```sh
echo "Your name is : ${myname:=John Doe}"
```

### 12. External Programs

The backtick (`)is also often associated with external commands.

* backtick simply catches the `standard output` from any command

```sh
find / -name "*.html" -print | grep "/index.html$"
find / -name "*.html" -print | grep "/contents.html$"

# 优化, find once
HTML_FILES=`find / -name "*.html" -print`
echo "$HTML_FILES" | grep "/index.html$"
echo "$HTML_FILES" | grep "/contents.html$"
```

### 13. Functions

A function may return a value in one of four different ways:

* Change the state of a variable or variables
* Use the `exit` command
* Use the `return` command
* echo output to stdout, which will be caught by the caller just as c=`expr $a + $b` is caught

* 函数不能改变传入的参数

函数会在一个`sub shell`中被调用, 当它的输出需要`pipe`到某个地方时

```sh
# `grep` 先启动, 然后把其 stdin 绑定到`ls`的 stdout.
ls | grep foo
```

### 14. Hints and Tips

Unix 操作 text 的工具很多, 有一些很强大. Vitually, Unix 内的一切都是`text`.

### 15. Quick Reference

| Command | Description                                | Example                                       |
| ------- | ------------------------------------------ | --------------------------------------------- |
| &       | Run the previous command in the background | ls &                                          |
| &&      | Logical AND                                | if [ "$foo" -ge "0" ] && [ "$foo" -le "9"]    |
| `||`    | Logical OR                                 | if [ "$foo" -lt "0" ] `||` [ "$foo" -gt "9" ] |
| ^       | Start of line                              | grep "^foo"                                   |
| $       | End of line                                | grep "foo$"                                   |
| =       | String equality                            | (cf. -eq) if [ "$foo" = "bar" ]               |
| !       | Logical NOT                                | if [ "$foo" != "bar" ]                        |
| -eq     | Numeric Equality                           | if [ "$foo" -eq "9" ]                         |
| -ne     | Numeric Inquality                          | if [ "$foo" -ne "9" ]                         |
| -lt     | Less Than                                  | if [ "$foo" -lt "9" ]                         |
| -le     | Less Than or Equal                         | if [ "$foo" -le "9" ]                         |
| -gt     | Greater Than                               | if [ "$foo" -gt "9" ]                         |
| -ge     | Greater Than or Equal                      | if [ "$foo" -ge "9" ]                         |
| -z      | String is zero length                      | if [ -z "$foo" ]                              |
| -n      | String is not zero length                  | if [ -n "$foo" ]                              |
| -nt     | Newer Than                                 | if [ "$file1" -nt "$file2" ]                  |
| -d      | Is a Directory                             | if [ -d /bin ]                                |
| -f      | Is a File                                  | if [ -f /bin/ls ]                             |
| -r      | Is a readable file                         | if [ -r /bin/ls ]                             |
| -w      | Is a writable file                         | if [ -w /bin/ls ]                             |
| -x      | Is an executable file                      | if [ -x /bin/ls ]                             |
| ( ... ) | Function definition                        | function myfunc() { echo hello }              |
