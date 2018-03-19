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
