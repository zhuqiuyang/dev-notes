### Pointer & Reference
1. Pointer:
- 地址(变量内容)
- 所指类型

```cpp
// 指向int类型的pointer
int* a
```
2. Ref
- `&`单独使用是*取址运算符*.
```cpp
int* p;
int a = 5;
p = &a;
```

- `&`用在初始化, 用于别名, 不开辟内存空间, 常用作函数传参
```cpp
int a = 5;
int &ra = a; // ra is the same as a, just use when 初始化
```

### Class & Structure
Class基于C的Structure
- 私有成员 write in first line, `private`可省略.
```cpp
class Array {
  int * Ap; int len; // private
  public:

}
```
structure 也可以定义类, 默认所有成员都是`public`
- 在class外定义成员需要使用`::`(作用域区分符)
- `.`, `->`用于访问对象成员