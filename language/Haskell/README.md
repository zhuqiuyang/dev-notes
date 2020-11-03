## Haskell 节要

### 1. 类型系统

> 易用的数据结构(基础)

* `data`
* `class`
* `newtype`
* `deriving`: 继承
* `instance`

### 2. 操作符

> Good syntax 易于描述算法

* `$`: 函数调用(右结合, 优先级最低)
* `.`: 函数 compose
* `-:`: pipe 传参 (hs 可以自定义操作符?)
* `<$>`: `fmap`
* `<*>`: 抽取第一个 ap 的函数, 作用于第二个 ap.
* `>==`: 接收一个 monad, 返回一个 new monad
* `>>`: 忽略第二个接收值, 始终返回第一个 monad
* `<=<`: monadic funtion compose
* `<-`: 从 IO/Monad 中提取 value

### 3. 概念

Functor:

* Functors are things that can be mapped over
* 更贴切的术语 functor is would be `computational context`. The `context` 可以是指其可能含有某个值 or 可能不会 (Maybe and Either a) , 又或者可能包含多个值(lists), stuff like that.

Applicator: mapping functions over functors

Monad: ap 升级版, ap 在 function full apply 即不可再继续, monad 可以一直 chain.

> eg: 走钢丝(walk the line)
