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
- 函数首字母不能大写
- 无参函数, 可视为`definition`(如下)
```hs
conano'Brien = "xxx"
```

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

通过`predicate`对`list`进行筛选 called **`filtering`**
- serveral predicates:
```hs
ghci> [ x | x <- [10..20], x /= 13, x /= 15, x /= 19]  
[10,11,12,14,16,17,18,20]
```

#### 2.6Tuples
两个元素的`Tuple`称作`pair`

### 3. Types and Typeclasses
#### 3.1 Believe the type
`:t` 用于检测数据类型
```hs
ghci> :t 'a'  
'a' :: Char
ghci> :t True  
True :: Bool
```

#### 3.2 Type variables
```hs
ghci> :t head  
head :: [a] -> a
```
代表`Type`必须大写, `a`此处表示 `type variable`
`a`可以是任何类型, 类似其他语言中`generics`
## 多态
**Functions** that have `type variables` are called **polymorphic functions**.

#### 3.3 Typeclasses 101
```hs
ghci> :t (==)  
(==) :: (Eq a) => a -> a -> Bool 
```
`=>`前称为`class constraint`

A `typeclass` is a sort of `interface` that defines some behavior.
- Eq, Ord, Show, Read ...

#### Type annotation (类型描述)
在`expression`end处添加`::`, 然后指定类型
```hs
ghci> read "5" :: Int  
5
```
* 所有numbers都是`polymorphic constant`(多态常量)

### 4. Syntax in Functions
#### 4.1 Pattern matching
定义: `Pattern matching`由指定的`patterns`组成, 对应数据会**check**是否与`pattern`一致, 或可根据`pattern`进行**deconstruct**.
- last should catch all !
> Note that (x:[]) and (x:y:[]) could be rewriten as [x] and [x,y] (because its syntatic sugar, we don't need the parentheses). We can't rewrite (x:y:_) with square brackets because it matches any list of length 2 or more.

- 递归定义:
```hs
sum' :: (Num a) => [a] -> a  
sum' [] = 0  
sum' (x:xs) = x + sum' xs  
```

- `xs@(x:y:ys)`, `@`前`xs`代表匹配的整体

#### 4.2 Guards, guards!
- 见4.3, 以`|`分隔
- `otherwise` catch all.
#### 4.3 Where!?
```hs
bmiTell :: (RealFloat a) => a -> a -> String  
bmiTell weight height  
    | bmi <= skinny = "You're underweight, you emo, you!"  
    | bmi <= normal = "You're supposedly normal. Pffft, I bet you're ugly!"  
    | bmi <= fat    = "You're fat! Lose some weight, fatty!"  
    | otherwise     = "You're a whale, congratulations!"  
    where bmi = weight / height ^ 2  
          skinny = 18.5  
          normal = 25.0  
          fat = 30.0
```
#### 4.4 Let it be
`let` 与 `where` 对比
- `where`在后定义
- `where` cross `guard`, `let`not.
- `let...in...` 是expression

#### 4.5 Case expressions
`pattern match` in expression 是`case expressions`的语法糖. (*)

### 5. Recursion
#### 5.1 Hello recursion!
- `Recursion`是一种定义`functions`的方式, 其会在内部调用自身.
- `edge condition`(基础条件): non-recursively, likely `F(0), F(1)`在Fibonacci.

#### 5.2 Maximum awesome
rewrite `maximum`: (elegant)
```hs
maximum' :: (Ord a) => [a] -> a  
maximum' [] = error "maximum of empty list"  
maximum' [x] = x  
maximum' (x:xs) = max x (maximum' xs)  
```

#### 5.3 A few more recursive functions (举例)
> `replicate`, `take` , `repeat`, `elem` ...

#### 5.4 Quick, sort!
Neat(!)
```hs
quicksort :: (Ord a) => [a] -> [a]  
quicksort [] = []  
quicksort (x:xs) =   
    let smallerSorted = quicksort [a | a <- xs, a <= x]  
        biggerSorted = quicksort [a | a <- xs, a > x]  
    in  smallerSorted ++ [x] ++ biggerSorted 
```
#### 5.5 Thinking recursively

### 6. High Order Function
Higher order functions 凝聚了很多Haskell的开发经验. 它证明, 如果你想 `define computations by defining what stuff is` instead of `defining steps that change some state and maybe looping them`, higher order functions 是不可缺少的.
> 如果更declative, higher order functions 是必不可少的.

## 6.1 Curried functions (重要)
默认所有Function都是单参的
- 所有多参函数, 都是**curried functions** 
- call a function少于它所需要的参数, 我们将得到**partial applied**function.

#### Some higher-orderism is in order
`->` 默认是`right accociation`
> Note: 为了简便, 称`a -> a -> a`为双参函数

#### Maps and filters
`map`和`filter`是一对搭档, 在FP中使用极广.
- 使用`map`解决问题(更易读), 也可用`list comprehension`替代.
  > `map (+3) [1,5,3,1,6]` same as `[x+3 | x <- [1,5,3,1,6]]`
- `takeWhile` 截取List直到`predicate`不满足
  > `takeWhile (/=' ') "elephants know how to party"` and it would return `"elephants"`
#### Lambdas
`lambda`是普通函数, 一般使用only once.

有些场景, partial applied更易读
- ` map (+x) [1..]` same as `map (\x -> x + 3) [1..]`