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