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
