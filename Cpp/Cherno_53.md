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

### 55. macro
