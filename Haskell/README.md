### 1. Introduction

#### 1.1 About this tutorial

#### 1.2 So what's Haskell?

* 纯函数式
* lazy
* 静态类型(但可以不显式声明)
* 精简

#### 1.3 What you need to dive in

```sh
ghci
:quit
```

### 2. Starting Out

#### 2.1 Ready, set, go!

* GHC
* prefix 函数转成 infix

```hs
div 92 10
-- 等于
92 `div` 10
```

`spaces` 用于表示函数调用

#### 2.2 Baby's first functions

* `else` 分支是必不可少的

```hs
doubleSmallNumber' x = (if x > 100 then x else x*2) + 1  
```

`'` 表示严格函数(not lazy)

* 函数首字母不能大写
* 无参函数, 可视为`definition`(如下)

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

* serveral predicates:

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

* Eq, Ord, Show, Read ...

#### Type annotation (类型描述)

在`expression`end 处添加`::`, 然后指定类型

```hs
ghci> read "5" :: Int  
5
```

* 所有 numbers 都是`polymorphic constant`(多态常量)

### 4. Syntax in Functions

#### 4.1 Pattern matching

定义: `Pattern matching`由指定的`patterns`组成, 对应数据会**check**是否与`pattern`一致, 或可根据`pattern`进行**deconstruct**.

* last should catch all !

  > Note that (x:[]) and (x:y:[]) could be rewriten as [x] and [x,y] (because its syntatic sugar, we don't need the parentheses). We can't rewrite (x:y:\_) with square brackets because it matches any list of length 2 or more.

* 递归定义:

```hs
sum' :: (Num a) => [a] -> a  
sum' [] = 0  
sum' (x:xs) = x + sum' xs  
```

* `xs@(x:y:ys)`, `@`前`xs`代表匹配的整体

#### 4.2 Guards, guards!

* 见 4.3, 以`|`分隔
* `otherwise` catch all.
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

* `where`在后定义
* `where` cross `guard`, `let`not.
* `let...in...` 是 expression

#### 4.5 Case expressions

`pattern match` in expression 是`case expressions`的语法糖. (\*)

### 5. Recursion

#### 5.1 Hello recursion!

* `Recursion`是一种定义`functions`的方式, 其会在内部调用自身.
* `edge condition`(基础条件): non-recursively, likely `F(0), F(1)`在 Fibonacci.

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

Higher order functions 凝聚了很多 Haskell 的开发经验. 它证明, 如果你想 `define computations by defining what stuff is` instead of `defining steps that change some state and maybe looping them`, higher order functions 是不可缺少的.

> 如果更 declative, higher order functions 是必不可少的.

## 6.1 Curried functions (重要)

默认所有 Function 都是单参的

* 所有多参函数, 都是**curried functions**
* call a function 少于它所需要的参数, 我们将得到**partial applied**function.

#### 6.2 Some higher-orderism is in order

`->` 默认是`right accociation`

> Note: 为了简便, 称`a -> a -> a`为双参函数

#### 6.3 Maps and filters

`map`和`filter`是一对搭档, 在 FP 中使用极广.

* 使用`map`解决问题(更易读), 也可用`list comprehension`替代.
  > `map (+3) [1,5,3,1,6]` same as `[x+3 | x <- [1,5,3,1,6]]`
* `takeWhile` 截取 List 直到`predicate`不满足
  > `takeWhile (/=' ') "elephants know how to party"` and it would return `"elephants"`
  #### 6.4 Lambdas
  `lambda`是普通函数, 一般使用 only once.

有些场景, partial applied 更易读

* `map (+x) [1..]` same as `map (\x -> x + 3) [1..]`

#### 6.5 Only folds and horses

* `folds`遍历 list, 返回 a signle value(acc)
  * 次序: `foldl`, `foldr`
  * `foldr1`: 使用第一个元素, 作为`acc`初始值
    > `folds`和`maps`, `filters`同为最常用的函数
* `scan` 返回`acc`的状态 list

#### 6.6 Function application with $

`$`和空格, 同为函数调用的两种方式

* `空格`是左结合
* `$`是右结合

```hs
sqrt (3 + 4 + 9)
-- same as
sqrt $ 3 + 4 + 9
```

`$` has the lowest precedence of any operator.

#### 6.7 Function composition

`.` 接收两个函数, 返回一个新的函数.

* point free 风格

### 7.Modules

#### 7.1 Loading modules

* `import Data.List`: 则`Data.List`exports 全局可用.
* `import Data.List (nub, sort)`: 导出指定
* `import Data.List hiding (nub)`
* `import qualified Data.Map as M`, 使用时则`M.filter`.

#### 7.6 Making our own modules

```hs
module Shapes
( Point(..)  
, Shape(..)  
, surface  
, nudge  
, baseCircle  
, baseRect  
) where
```

通过`Shape(..)`(8.1 例子), `Shape`的所有 value constructor 都会被导出

### 8. Making Our Own Types and Typeclasses

#### 8.1 Algebraic data types intro

* 通过`data`来自定义 data type
* `value constructors` 是函数, 接收一些列参数, 返回相应的 value of some type.

#### 8.2 Record Syntax

better way than `data Person = Person String String Int Float String String deriving (Show)`

```hs
data Person = Person { firstName :: String  
                     , lastName :: String  
                     , age :: Int  
                     , height :: Float  
                     , phoneNumber :: String  
                     , flavor :: String  
                     } deriving (Show)
```

Record Syntax 优势:

* 自动 create 取值函数`firstName::Person -> String`
* when `derive`from `Show`, 展示出具体字段名

  ```hs
  data Car = Car String String Int deriving (Show)  

  ghci> Car "Ford" "Mustang" 1967
  Car "Ford" "Mustang" 1967
  --
  data Car = Car {company :: String, model :: String, year :: Int} deriving (Show)  

  ghci> Car {company="Ford", model="Mustang", year=1967}
  Car {company = "Ford", model = "Mustang", year = 1967}  
  ```

#### 8.3 Type parameters

`data Maybe a = Nothing | Just a`, 由于`a`是一个`type parameter`, 所以我们称`Maybe`是`type constructor`.

* `Just 'a'` 的 type 为`Maybe Char`
* empty list(`[]`)的 type 为`[a]`
  > 所以我们可以进行`[1,2,3] ++ []`和`["ha","ha","ha"] ++ []`操作.

`Type paramter`适用于`List`, `Maybe`这类不关心元素具体类型的 type.

> 不要在 data declaration 中添加 typeclass 限制, 放在函数的 type declaration 中.

`data Vector a = Vector a a a deriving (Show)`:

* `=`前的`Vector`是 **`type constructor`**
* `=`后的`Vector`是 **`value constructor`**

#### 8.4 Derived instances

```hs
data Day = Monday | Tuesday | Wednesday | Thursday | Friday | Saturday | Sunday
           deriving (Eq, Ord, Show, Read, Bounded, Enum)

ghci> Wednesday  
Wednesday  
ghci> show Wednesday  
"Wednesday"  
ghci> read "Saturday" :: Day  
Saturday
ghci> Saturday > Friday  
True  
ghci> Monday `compare` Wednesday  
LT  
```

#### 8.5 Type synonyms

**type synonyms**: `String`和`[Char]`是相等且能 interchangable(可交换的).

```hs
type String = [Char]
```

#### Type synonyms can also be parameterized (参数化)

```hs
type AssocList k v = [(k,v)]
```

### concrete type

`AssocList`: is a `type constructor` + two `types` => **`concrete type`**(like `AssocList Int String`, **fully applied types**, `type constructor`完整调用).

> `data Int = ...`, 无参的`type constructor`, 本身就是 concrete type.

### 自己理解-与*data*定义的`type constructor`的区别

* `data`的`type constructor`主要定义`type`的具体内部实现
* `type`主要定义别名.

#### Either

`data Either a b = Left a | Right b deriving (Eq, Ord, Read, Show)`

* Maybe 不能展示 failure 的信息, Either 可以.

#### 8.6 Recursive data structures

algebratic data types 实现 List:

```hs
data List a = Empty | Cons a (List a) deriving (Show, Read, Eq, Ord)
```

当我们把 function 定义成操作符, 需要使用`fixity声明`

```hs
-- 自定义一个操作符 :-:
infixr 5 :-:
data List a = Empty | a :-: (List a) deriving (Show, Read, Eq, Ord)
```

`*`的 fixity 是`infixl 7 *`.(数值越高优先级越高, `infixl`代表中缀, 左结合)

#### 8.7 Typeclasses 102

```hs
class Eq a where  
    (==) :: a -> a -> Bool  
    (/=) :: a -> a -> Bool  
    x == y = not (x /= y)  
    x /= y = not (x == y)
```

`a`是一个 concrete type, 因为函数只接收 concrete type. (举例: 函数的 type 不能为`a -> Maybe`, 但是可以是`a -> Maybe a`,或`Maybe Int -> Maybe String`)

```hs
instance Eq TrafficLight where  
    Red == Red = True  
    Green == Green = True  
    Yellow == Yellow = True  
    _ == _ = False  
```

`class`关键字用于定义一个新的`typeclass`, `instance`is for making our `types instances` of `typeclasses`.
`instance Eq TrafficLight where`.我们用`actual type`替换了`a`

##### subclass

```hs
class (Eq a) => Num a where  
   ...
```

#### 8.8 A yes-no typeclass

#### 8.9 The Functor typeclass

```hs
class Functor f where  
    fmap :: (a -> b) -> f a -> f b  

instance Functor Maybe where  
    fmap f (Just x) = Just (f x)  
    fmap f Nothing = Nothing  
```

`f`是一个`type constructor`,可以使`Maybe`, `Either a`

#### 8.10 Kinds and some type-foo

* 未读

`type constructor`和`function`有很多共同之处, 但两者是完全不同的东西.

### 9. Input and Output

Haskell 对`pure`和`impure`做了分离.

#### 9.1 Hello, world!

```hs
main = do  
    putStrLn "Hello, what's your name?"  
    name <- getLine  
    putStrLn ("Hey " ++ name ++ ", you rock!")
```

* `main`的 signature 是`mian :: IO something` (something 是`concrete type`)
* `do`把多个`IO`合并成一个
* `<-` 从`IO`结果中获取数据
* `getLine`Action 是**impure**的, 因为执行多次, 并不能确保结果一致

### 10. Functionally Solving Problems

#### 10.1 Reverse Polish notation calculator

#### 10.2 Heathrow to London

#### 11. Functors, Applicative Functors and Monoids

**computation context**比喻`Functor`, 更确切

#### 11.1 Functors redux

#### 11.2 Applicative functors

#### 11.3 The newtype keyword

#### 11.4 Monoids
