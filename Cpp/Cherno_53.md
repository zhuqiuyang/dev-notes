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
* 造成 compiler 识别 ambigious, 两个 namespaceing 下有同名内容.

Eg: `EASTL`
