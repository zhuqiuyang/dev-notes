# Dev-notes

Dev Learning Notes

### 平衡: 易用, 高效, 安全

> 易用: 少写 code, 高复用.
>
> 高效: High Performance: 充分利用计算(CPU)及存储(Memory)资源
>
> 安全: 根本前提(eg: 并发竞争, 指针访问不越界/不泄露)

#### 易用的产物:

* OOP(class), FP(Functor), Macro(code-> code), 各种语法 Sugar
* 简化并发模型:
  * Go 的 channel
  * Node 的 event-driven, non-blocking I/O 模型
  * Erlang/Elixir 的 Actor 模型(未接触)

#### 高效的产物

* Pointer(指针), Ref(引用)
  > 减小 Copy Cost, 但增加了开发难度

#### 安全的产物

* 编译检查: C++ Declaration, Haskell 类型系统
* js workflow: Typecript
