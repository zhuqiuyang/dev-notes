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

- `this`是一个常指针, 相当于
```cpp
// class_Type 是类类型标示符
class_Type * const this
```
对象初始化之后, `this`不可修改

```cpp
class X {
  int a;
  int f() {
    return a++;     // legal
  }
  int g() const {
    return a++;     // wrong!
  }
};
```

常成员函数不允许修改, `this`所指对象的成员
```cpp
const X * const this
```

### Function
1. inline function:
1~5 行的小程序, 减小调用开销
- 第一次声明需用`inline` 关键字, 否则被视为普通函数
- 不能包含: 循环, 分支语句
- 不能包含递归调用.

2. 重载(简单地多态)

3. Vitual Function(动态联编)
- `switch` 属于动态联编.