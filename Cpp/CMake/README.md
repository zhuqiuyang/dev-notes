### Compiling C++ using CMake and Make (CS20170204)

> https://www.youtube.com/watch?v=elycr5wi9_g
> 
> 现实中, Hundred of CPP file to build.
> 
> Cmake会生成 Makefile

### CMakeLists.txt

* 首行指定, 最低要求版本
* `set`设置 variable
  * `set(CMAKE_CXX_FLAG " ${CMAKE_CXX_FLAG}-std=c++14")`: new value & initial value
* project(name)