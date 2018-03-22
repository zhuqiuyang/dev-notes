### Xcode setting

```sh
-- Install configuration: ""
-- Installing: /usr/local/include/GLFW
-- Installing: /usr/local/include/GLFW/glfw3.h
-- Installing: /usr/local/include/GLFW/glfw3native.h
-- Installing: /usr/local/lib/cmake/glfw3/glfw3Config.cmake
-- Installing: /usr/local/lib/cmake/glfw3/glfw3ConfigVersion.cmake
-- Installing: /usr/local/lib/cmake/glfw3/glfw3Targets.cmake
-- Installing: /usr/local/lib/cmake/glfw3/glfw3Targets-noconfig.cmake
-- Installing: /usr/local/lib/pkgconfig/glfw3.pc
-- Installing: /usr/local/lib/libglfw3.a
```

* build Settings: Header Search Path: `usr/local/include`
* build Phase: Link Binary with libray:
  * `OpenGL.framework`
  * `/usr/local/Cellar/glfw/3.2.1/libglfw.3.2.dylib` (`brew install glfw3` 之后)
    > `cmd+shift+g`: Finder 跳转到指定目录
