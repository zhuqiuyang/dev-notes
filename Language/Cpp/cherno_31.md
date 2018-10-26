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
* ASCII 表中`\0`, 代表`NULL`, 字符串的结尾
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

### 33. String Literals in C++

> string literal: a series of char in ""

```cpp
// const char array, size is 7
"Cherno"

const char name[8] = "Che\0rno";
// c string, get length is 3!
std::cout << strlen(name) << std::endl;
```

```asm
CONST SEGMENT
??_C@ ....; `string'
CONST ENDS
```

* string literal 存储在只读 memory 中.

```cpp
char* name = "Ace";
name[2] = 'c';

std::cout << name << std::endl;
```

* `name`存在于只读内存, 不能修改. (禁止这么做)

```cpp
using namespace std::string_literals;

std::string name0 = "Ace"s + "Hello";
// c14
std::string name01 = "Ace"s + "Hello";

const char* example = R"(Line1
Line2
...)";
const char* ex =
    "Line1\n"
    "Line2\n"
    "Line3";
```

* `s`一个 function return a `std::string`

#### Memory of string literal (how works? 11: 22)

> always read only. (ASM 级别解释, `const char* name[] = "", name[2] = 'a'`可行的原因)

### 34. CONST in C++

> fake keyword, 对 generate code 作用很小,
>
> promise: not change data. 这么承诺, 是因为可以简化 code.

1.  应用于 pointer
    > see code (03:40)

```cpp
const int* a = new int;
```

* `*`之前用于约束 pointer 指向的 content 是`const`.(`a`的值可以改变.)

```cpp
int* const a = new int;
```

* `*`之后约束 pointer 自身值不可改变.

2.  class & method:

```cpp
class Entity {
  int m_x, m_y;

 public:
  int getX() const { return m_x; }
};
```

* `const` at the right of method 意味着不改变 class 任何值.

```cpp
class Entity {
  int* m_X, m_Y;

 public:
  const int* const GetX() const { return m_X; }
};
```

* 上述方法 means: 返回一个`const pointer`, 且其指向 content 为`const`, and this method promise 不改变 class.
* 上述: `m_X`是 pointer, `m_Y`仍是 integer, 如果都是 pointer, 改写成`int* m_X, *m_Y`

```cpp
void PrintEntity(const Entity& e) {
  // 此处GetX method必须是const!
  std::cout << e.GetX() << std::endl;
}
```

* 在这`e`就是`Entity`(引用), 不可改变 e 的 content.
* 作者建议:always mark your method as const, if 它不需要改变 class.

#### Debug 或者其他情况: 我们需要 modify 某些 varibale, 但仍不改变 const method 的行为

> mutable keyword.

```cpp
class Entity {
  mutable int var

 public:
  int getX() const {
    var = 2;
    return m_x;
  }
};
```

### 35. The Mutable Keyword in C++

use:

1.  const

```cpp
class Entity {
  private:
    mutable int var = 0
}
```

* `mutable` here 表示 allow const method to change it .
* 这几乎是在 class 中使用`mutable`的唯一场景. (Debug)

2.  lambda

```cpp
int x = 8;
auto f = [=]() mutable
{
  x++;
  std::cout << "Hello" << std::endl;
};
f();
```

> `&`pass by ref, `=`by value
