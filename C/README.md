### Gcc 常用

```sh
gcc
# -c: 生成目标文件
# -I[dir]: index头文件
# -l[library]: search library 在link 阶段
# -L[dir]: Link库
# -o: 输出
# -W[all]: 输出warn信息(all)
```

### 个人简解

> C 就两点: 类型, 指针

- 一切定义先有类型`type`: `struct`, `typedef`, `#define`
- 一切皆可指向`pointer`: 可以指向一切. (ptr 也需要`类型`)

### 制作 static library

> ./static_lib;

```sh
gcc -Wall -c hello_fn.c && gcc -Wall -c bye_fn.c

# ar : 把多个 files combined into an archive.
# c: crate, r: replace, s: write the index
ar crs libhello.a hello_fn.o bye_fn.o

# t 表示: content, 显示包内容.
ar t libhello.a

gcc -Wall main.c libhello.a -o hello

# Link
gcc -Wall -L. main.c -lhello -o hello
```

- Link external Lib

```sh
# 两者等同
gcc -Wall calc.c /usr/lib/libm.a -o calc
gcc -Wall calc.c -lm -o calc
```

> `-lNAME` 尝试 link object files with a library file `libNAME.a` in the standard library directories

### The C Programming Language

#### Chap 1

- C 语言本身没有定义输入/输出功能, `printf`是函数库提供的.

> ./work_space/temp.c

- `#define name value`: 增加可读性

```sh
gcc -Wall temp.c -o temp.o
```
