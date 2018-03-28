### 31. Arrays in C++

> 先要 know pointer.

* 便于 create a collection of data, 而非创建一堆 variable.

```cpp
int examples[5];
int* ptr = examples;
```

* `examples`实际是 `integer pointer`(存储的数组的首地址)

```cpp
examples[2] = 5;
*(ptr + 2) = 6;
*(int*)((char*)ptr + 8) = 7;
```

* `ptr + 2` 所加的值是索引值, byte 长度会根据所指的数据类型, 被 add.
* `char`占 1 byte, 所以 +8, 实际是`int`的长度.

#### create in Heap

```cpp
int* another = new int[5];

delete[] another
```

* 当 function 返回一个新的数组时, need `new` keyword.

#### cpp11: std::array

* 默认 array 无法直接获取长度. 可以用`sizeof(examples)/sizeof(int)`
* 作者使用`raw array`, 因为会 fast 一些.
* 使用`std::array` 会更安全一些.

### 32. How Strings Work in C++ (and how to use them)

> string : a group of text
>
> Talking about: English, char 在 Cpp 中占 1byte

#### how works

> string is an array of characters.

```cpp
int main() {
  const char* name = "Ace";  
  // will error !
  name[2] = 'c';
  char name2[4] = {'A', 'c', 'e', '\0'};
  // actual value
  char name3[4] = {'A', 'c', 'e', 0};
}
```

* string is immutable, fixed allocated block memory.
* double quote `""`, 默认声明一个`char pointer`(字符指针)
* ASCII 表中`\0`, 代表`NULL`, 字符串的结尾
* stand lib of CPP 有一个`String` class;
* `std::String` is a template version of that basic `String` class.

#### how to use (12:19)

* `std::string`的`constructor`接收`char pointer`或者 `const char pointer`作为参数
* `include <string>` 包含了 对 `<<` 运算符的 overload, 允许我们在`cout`中使用.

```cpp
std::string name = "Ace";
// append string, `+=` is overload
name += "Hello";
```

2.  string 传参

```cpp
void printString (std::string string) {

}

void  printString (const std::string& string) {}
```

如上定义会进行`class`/object copy, 开销大, 改进:

* Ref, won't copy it .

### 35. CONST in C++

> fake keyword, 对 generate code 作用很小,
>
> promise: not change data. 这么承诺, 是因为可以简化 code.

1.  应用于 pointer
    > see code (03:40)
