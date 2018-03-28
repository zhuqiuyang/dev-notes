### 21. Static in C++

`staic`有两种意义(根据 context):

* inside class/struct: shared memory 在所有 `instance` 中.
* outside class/struct: means `internal`, 只在定义所在的 `translation unit` 可见.

> 这节课只讨论 outside class 的场景(类似于 class 中的 private.04:50)

```cpp
static int s_Variable = 5;
```

* only 被 linked internally inside this Translation unit, 不能被其他 unit Link (\*)
* `staic` Function or var 意味着: link 阶段只会在`Translation unit`内寻找`symbol definition`

```cpp
extern int s_Variable;
```

* 在`Translation unit` 之外寻找这个`s_Variable`;

在`.h`中创建`static` variable: 在所有引用这个`.h`文件中都创建了`static` variable;

#### 作者建议:

尽量让你的 variable 和 function static, 除非你希望 them to be linked cross translation unit.

### 22. Static for Classes and Structs in C++

> global instance for that class.

```cpp
struct Entity {
  static int x, y;
};

// error: Because x, y are not class member now!
Entity e1 = {5, 8};

// correct:
int Entity::x = 5;
int Entity::y = 8;
```

* `static member`在 class 中是只是声明, 必须在 class 外初始化和定义, (用以分配空间并初始化) - book&video03:12
* we made two variable x&y, inside a namespace called `Entity`, they 不属于 class `Entity`.

#### 这么做的意义:

当你有 data 希望在所有的 instance 之间 shared, store it inside the `Entity` class, 虽然创建一个`staic global` variable 也可行.

* static method 不能访问 non-static variable: 因为 static method doesn't have a class instance.
* class 的每个 non-static method, always get a class instance as parameter.(内部机理)
  * `method` just function with a hidden parameter.
  * `static` method 却没有, it's same 如果 write a function outside the class.

使用建议: `static` 对于 `static data`(doesn't change between class instances) 十分有用.

### 23. Local Static in C++

> lifetime 整个 program 运行周期, scope inside the function.

```cpp
void Function() { static int i = 0; }
```

* first call 初始化 i, 之后不会再 create. (eg: 每次调用, +1)
* 创建一个`Singleton` Class 也可以实现, 相比则会有 a lot of code.

使用场景:

* singleton
* 初始化 function.

### 27. Inheritance

write `:`(colon) 在 class 声明之后, 添加基类

```cc
class Entity
{
  public:
    float X, Y;

    void Move(float xa, float ya) {
      X += xa;
      Y += ya;
    }
};

class Player : Entity
{

}
```

* 子类包含父类所有的东西.

### 28. Virtual Functions in C++

```cc
#include <iostream>

class Entity
{
public:
    std::string GetName() {return "Entity";}
};

class Player : public Entity
{
private:
    std::string m_Name;
public:
    Player(const std::string& name)
    : m_Name(name) {}

    std::string GetName() { return m_Name; }
};

int main(int argc, const char * argv[]) {
    Entity* e = new Entity();
    std::cout << e->GetName() << std::endl;

    Player* p = new Player("Cherno");
    std::cout << p->GetName() << std::endl;

    std::cin.get();
}
```

问题: 上述代码中增加

```cc
Entity* entity = p;
std::cout << entity->GetName() << std::endl;

void PrintName(Entity* e) {
    std::cout << e->GetName() << std::endl;
}
```

`PrintName`输出的永远是基类 Entity 的 name, 这是正常的.
如果我们想让它在传入子类对象时, 输入其属性.

#### 内部原理:

`virtual` 告诉 compiler, 为这个 function 生成一个 vtable(虚拟表), overwritten 时, 指向 correct 的 function. (04:35)

```cc
virtual std::string GetName() {return "Entity";}
```

`C++11`中增加了`override`

```cc
std::string GetName() override { return m_Name; }
```

更好的语义, 便于 compiler 检查 (只能 override 基类中已定义的 virtual funciton).

#### two runtime cost.

* 额外的内存, 维护 vtable
* 每次 call, 都会通过 vtable 查找, call 正确的 function.

> CPU 紧缺的嵌入式系统, 少用

### 29. Interfaces in C++ (Pure Virtual Functions)

> pure function in c++ , 如同 JAVA, C# 中的 interface
>
> Cpp 中 interface 就是 class.

```cpp
class Entity
{
public:
    virtual std::string GetName() = 0;
};
```

* 拥有`pure virtual function`的 class 称为`abstract class`
* 不实现基类的`pure virtual function`, 这个类不能被初始化.

#### 结论(使用场景-Generic): (!!!)

* 确保 some `class`拥有 certain function, 所以你可以 pass it to `fairly generic method` that we'll just call that function.

### 30. Visibility in C++

> visible: who can see/call/use them ?
>
> vidibility 并不是 program 实际运行方式, just for write better code.(help organize code) !!!

#### private:

* itself 和 friend 可以访问 private members;
* `main()`中不可以访问

#### protected:

* subclass 可以访问 protected members;
* `main()`中不可以访问

#### public

* Public for all, anyone can Access.

##### TLDR; (short answer)

> 作者阐述 When and why to use visibility ?

个人理解:

* 便于维护, 长期之后, 知道哪些内容是被保护的, 防止破坏
* 暴露的 API 是 public, 内部实现可以是 private.
