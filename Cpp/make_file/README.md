> https://www.youtube.com/watch?v=aw9wHbFTnAQ (256k)
>
> https://www.tutorialspoint.com/makefile/why_makefile.htm

```sh
g++ main.cpp function1.cpp function2.cpp -o hello
```

* `.o`是 excutable file
* 单独运行`make`会运行`Makefile all:`下的 command
* `make install` 会运行 `Makefile install`下的 command
* `hello: main.o function1.o function2.o`后面三个是`hello`的依赖
* `make all`执行后, 更改`main.cpp`, 在运行`make all`, 只编译被影响的部分.
