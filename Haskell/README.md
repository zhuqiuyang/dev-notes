### 1. Introduction

#### 1.1 About this tutorial

#### 1.2 So what's Haskell?

* 纯函数式
* lazy
* 静态类型(但可以不显式声明)
* 精简

#### 1.3 What you need to dive in
### 2. Starting Out
#### 2.1 Ready, set, go!
- GHC
- prefix 函数转成 infix
```hs
div 92 10
-- 等于
92 `div` 10
```
`spaces` 用于表示函数调用

#### 2.2 Baby's first functions
- `else` 分支是必不可少的

```hs
doubleSmallNumber' x = (if x > 100 then x else x*2) + 1  
```
`'` 用于表示严格表示函数

#### 2.3 An intro to lists

* 元素类型 must 一致 (homogenous)
* `++` put two list together
* index
```hs
ghci> "Steve Buscemi" !! 6  
'B'  
```

```hs
[1,2]
```

#### 2.4 Texas ranges

* 长度上限
* 步长

```hs
[1..100]
```

#### 2.5 I'm a list comprehension
```hs
ghci> [x*2 | x <- [1..10], x*2 >= 12]  
[12,14,16,18,20]  
```

#### 2.6Tuples
两个元素的`Tuple`称作`pair`
