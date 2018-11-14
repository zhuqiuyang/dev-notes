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
- OOP: `class -> Object`
- FP: `Functor.map(fn) -> Functor`

3. 不同泛型中, 优秀的思想

- Lisp Macro: `generator code`

4. 约束: `为了大型工程`

- 强数据类型
- 不可变: `const, static`
- 访问控制: `public, private`
- 继承控制: `final`

4. 动/静态

- 静态: 所有操作`runtime`前完全 ok
- 动态: `runtime`时, 可以通过`data -> 操作`
