## 学习准则

1. 跟准一个老师

2. 不必在技术上投入太多时间, `见性就都通达了`

### 程序, 即数据

1. 编程就是: `定义和操作`**数据**

- 数据
  - 基本数据类型(狭义): `int, string, boolean`
  - 复合类型: `structure, Obejct ...`
- 操作:
  - 函数(狭义): (`Lisp 中 data -> procedure`)
  - 运算符: `算术, 逻辑`
  - 结构: `循环结构, 分支结构`

2. 编程泛型:

- List: `数据/函数调用` 使用同一泛型
- OPP: (procedure)
  - 类 c: `c, go, js`
- OOP: `class -> Object`
- AOP
- FP: `Functor.map(fn) -> Functor`

### 程序管理

1. 约束: `目的: 拍错 & 易管理`

- 强数据类型
- 不可变: `const, static`
- 访问控制: `public, private`
- 继承控制: `final`

2. 减少代码量: `目的: 少, 易管理`

- 生成代码: `macro`

3. 更高编程能力: `目的: 突破限制, idea -> 实践`

- 手段: `data -(编译器/解释器)-> data/操作`(获得更多动态特性)

### (待定)

1. 动/静态

- 静态: 所有操作`runtime`前完全 ok
- 动态: `runtime`时, 可以通过`data -> 操作`

2. 不同泛型中, 优秀的思想

- Macro(Lisp, C): 调用 compiler `generator code`
- AOP:
  - `横切, 讲Object 构建的庞大体系, 进行水平的切割`
  - 影响到多个 Class 的行为, 封装成可重用的模块, 即 `切面`
  - 通过**代理**操作(Object), 切面可自定义
- IOC:
  - 通过`配置文件 or 注解`, 让`Class`被统一管理.(装载, 实例化, 调用)
- 并发编程& 异步控制
  - js: `基于事件的non-blocking I/O模型, cb`
  - go: `channel, goroutine`
