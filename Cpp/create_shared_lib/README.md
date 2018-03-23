> https://www.youtube.com/watch?v=PRUR_bN3r-E
>
> `mylib.h`, `mylib.cpp`
>
> `clang | klaŋ |`

```sh
# 编译mylib
chmod +x compile_lib.sh

# 编译引用mylib的cpp
chmod +x compile_prog.sh

# 测试运行
./a.out
```

### Static vs. Shared Libraries

> https://www.youtube.com/watch?v=-vp9cFQCQCo

1.  Why we need? : 支持 application excute

* Shared Lib: `.so`, `.dylib`(osx), `.dll`(windows)
  * Run-time Call: App code 只保存一个 Shared Lib 的 Reference..
* Staic Lib: `.a`, `.lib`(window)
  * Use at Compile-Time (6:07): Literally copy & move to the app code.
