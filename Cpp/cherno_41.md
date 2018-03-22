### 49.Using Libraries in C++ (Static Linking)

> Cpp no package manager.

典型的 Cpp Library 有两部分:

* includes: a bunch of `.h`(开发时通过`#include`引用)
* library: prebuild binaries. (Link 时, `-l`把此目录包含, 则可搜索到)

> 参考 opencv 安装: https://www.youtube.com/watch?v=U49CVY8yOxw

```sh
 cd <glfw-root-dir>
 mkdir glfw-build
 cd glfw-build
 cmake ..

 # 生成include 和 lib
 export DESTDIR=/INSTALL/DIR
 # make install
 sudo make install

 # Xcode: Header search path 加入`include`; Lib Search Path 加入 lib (静态?); Link Phase 加入 lib (动态)
```

two phase for this: (其他 vedio 内涉及)

* dynamic lib (actually linked at run-time)
* static lib (inside excutable file)

Cherno 老师 like do `static linking`whenerver possible.

* fast, do some 优化

This vedio 两种 linking 都演示: (08:50)
