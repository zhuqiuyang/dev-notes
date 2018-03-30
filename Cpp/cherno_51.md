### 52: How to Deal with Multiple Return Values in C++

> tuple

* same type: 使用 vector or array.

#### 返回多 type

1.  use `struct`: 然后 destructure 去除 (作者推荐的方式, end 介绍: 14:59)
    > 易用, 代码清晰

```cpp
struct ShaderProgSource {
  std::string vs;
  std::string fs;
}
```

2.  创建多个`variable`,(命名成`out`06:56) 传给调用函数(其内赋值)

    > 暂不讲 optimization

3.  返回一个 Array (09:00)

```cpp
return std::array<string, 2>(vs, fs);
```

* 或者 vector
  > array in stack, vector in heap

4.  Tuple(pair)

    > Tuple is a class 可以包含 X amount of variables(不关心 type)

// 12:15

```cpp
#inclue <utility>
static std::tuple<std::string, std::string> functionName() {}

return std::make_pair(fs, vs);

auto sources = functionName();
// souces.first, souces.second
std::string vs = std::get<0>(sources);
```

* 作者 hate 这种`get`方式

### 53: template

> 有一点像 macro

1.  use template in function

* `T`可以用任何 name 代替
* `<int>`可以省略
* `template`也可以用`class`, 不过前者语义更好.
* template 不存在, untile 我们 call it .

```cpp
#include <iostream>
#include <string>

template <typename T>
void Print(T value) {
  std::out << value << std::endl;
}

int main() {
  Print(5);
  Print<int>(5);
  Print("Hello");
  Print(5.5f);

  std::cin.get();
}
```

2.  use template in class

```cpp
#include <iostream>
#include <string>

template <typename T,int N>
class Array
{
private:
  T m_Array[N];
public:
  int getSize() const { return N; }
}

int main() {
  Array<int, 5> array;
  std::out << array.getSize() << std::endl;

  std::cin.get();
}
```

#### 总结

* runtime 调用 compile write code for you, 十分 powerful
* 适合的 situatio: login system,
* 避免 generate 出来的 code 难以理解.

### 54. Stack vs Heap Memory in C++

不同的是如何 allocate memory,

eg: allocate 3 中不同的 type

```cc
#include <iostream>
#include <string>

struct Vector3 {
  float x, y, z;

  Vector3() : x(10), y(11), z(12) {}
}

int main() {
  // stack
  int value = 5;
  int array[5];
  Vector3 vector;

  // heap
  int* hvalue = new int;
  *hvalue = 5;
  int* harray = new int[5];
  Vector3* vector = new Vector3();
}
```

#### allocate:

* stack pointer, 从 top 开始 move, 按需分配内存;(extremly fast, move stack pointer)
* heap 分配空间非连续: make unique, make shared. 和 new 基本相同, 需要 `delete`手动删除.

#### Free:

* stack 释放只需移动 stack pointer backward 即可.
  > GC 的瓶颈在 heap 内的回收, Cpp 手动 delete, 所以性能好? (pc.)

#### How Heap works, and new, delete do?

* `new` call `malloc`(memory allocate)
* 统一向 OS 预申请, Freelist 记录, 程序使用时再内部分配, (bookeeping 哪些已使用); 过大了再动态向 OS 申请(big cost)

最大的不同在于`allocate`:

* allocate in heap is a whole thing (巨大的), in stack is like one CPU instruction.
* `delete` in heap is incredibly heavy as well.

#### 建议

`任何时候尽可能`在 stack 中 allocate, fast 且性能好. 例外 eg: 你希望 lifetime longer than the scpoe of your funciton; 载入一个大型 15MB 的文本;

one more time, the performance 差距来自于`allocate`, 假设你在程序运行前`pre-allocate`一块 GB 级 block for heap, allocate 性能基本一致. ask`new` 需要申请, 然后`bookeep`, 此时这是 slow part.

### 55. macro

> gcc: A macro is a fragment of code which has been given a name. Whenever the name is used, it is replaced by the contents of the macro.
>
> 不建议 overuse macros, 不易读.

```cc
#include <iostream>
#include <string>

#define LOG(x) std::out << x << std::endl

int main() {
  LOG("HELLO");
  std::cin.get();
}

#define MAIN int main() \
{\
  std::cin.get();\
}
```

### 60. Why I don't "using namespace std"

> `using namespaceing std` 不用 type`std::`every time, 也可以定义在函数 scope 中.
>
> js 中的`with`与之类似.

* 便于一眼看出, 使用了`std`库中的哪些函数.
* 避免 possible error.造成 compiler 识别 ambigious, 两个 namespaceing 下有同名内容.

Eg:

1.  `EASTL`
2.  `apple`and `orange`事例:

* `print("Hello");`中的`"Hello"`是`(const char[6])"Hello"`
* 如果没有`orange`中的, 将进行`implicit conversion` (隐式转换)

## Never use namespace in `.h`

* 如果使用, 尽量 inside function scope, also not in `.cpp`

> 很难 Track 到哪里 include, 哪里没有 (13:00)
