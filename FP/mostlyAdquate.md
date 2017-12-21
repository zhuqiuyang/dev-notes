## Chapter 1: What ever we are doing?
In order to be able to understand the following chapters, we must have some idea about what makes a program **functional**.

We need a **clear** bullseye to hurl our code at, some celestial compass for when the waters get rough.

> Don't despair - throughout this book, we'll sprinkle in some `category` theory, `set` theory, and `lambda calculus` and write real world examples that achieve the same elegant simplicity and results as our flock of seagulls example. You needn't be a mathematician either. It will feel natural and easy.
>
> obey the laws of math.
> 
> (we'll go over the precise definition of "imperative" later in the book, but for now consider it anything other than functional programming). The payoff of working within a principled, mathematical framework will truly astound you.

## Chapter 2: First Class Functions

尽可能少使用`this` in js.
如果为了`this`能提高性能而是用, 还是合上这本书吧.

## Chapter 3: Pure Happiness with Pure Functions
> A pure function is a function that, given the same input, will always return the same output and does not have any observable side effect.
```js
var xs = [1, 2, 3, 4, 5];

// pure
xs.slice(0, 3);
//=> [1, 2, 3]

xs.slice(0, 3);
//=> [1, 2, 3]


// impure
xs.splice(0, 3);
//=> [1, 2, 3]

xs.splice(0, 3);
//=> [4, 5]

// impure
var minimum = 21;

var checkAge = function(age) {
  return age >= minimum;
};



// pure
var checkAge = function(age) {
  var minimum = 21;
  return age >= minimum;
};
```
### Side Effect

> It is not that we're forbidden to use them, rather we want to contain them and run them in a controlled way. We'll learn how to do this when we get to *functors* and *monads* in later chapters, but for now, let's try to keep these insidious functions *separate* from our pure ones.

Of course, you might want to calculate instead of hand writing things out, but this illustrates a different way to think about functions.
```js
var toLowerCase = {
  'A': 'a',
  'B': 'b',
  'C': 'c',
  'D': 'd',
  'E': 'e',
  'F': 'f',
};

toLowerCase['C'];
//=> 'c'
```
> Here comes the dramatic reveal: Pure functions are mathematical functions and they're what functional programming is all about. Programming with these little angels can provide huge benefits. Let's look at some reasons why we're willing to go to great lengths to preserve purity.

### The case for purity
#### Cacheable
```js
var squareNumber = memoize(function(x) {
  return x * x;
});

squareNumber(4);
//=> 16

squareNumber(4); // returns cache for input 4
//=> 16
```
#### Portable / Self-Documenting
```js
//pure
var signUp = function(Db, Email, attrs) {
  return function() {
    var user = saveUser(Db, attrs);
    welcomeUser(Email, user);
  };
};

var saveUser = function(Db, attrs) {
    ...
};

var welcomeUser = function(Email, user) {
    ...
};
```
> Contrary to "typical" methods and procedures in imperative programming rooted deep in their environment via state, dependencies, and available effects, pure functions can be run anywhere our hearts desire.
>
> When was the last time you copied a method into a new app? One of my favorite quotes comes from **Erlang** creator, Joe Armstrong: "The problem with object-oriented languages is they’ve got all this implicit environment that they carry around with them. You wanted a banana but what you got was a gorilla holding the banana... and the entire jungle".

## Chapter 4: Curry
Giving a function fewer arguments than it expects is typically called **partial** application.

> higher order functions(Higher order function: A function that takes or returns a function).

```js
var _ = require('ramda');

// Exercise 1
//==============
// Refactor to remove all arguments by partially applying the function.

var words = function(str) {
  return _.split(' ', str);
};

// =>
var words = _.split(' ');

// Exercise 1a
//==============
// Use map to make a new words fn that works on an array of strings.

var sentences = undefined;

// =>
var sentences = _.map(words);


// Exercise 2
//==============
// Refactor to remove all arguments by partially applying the functions.

var filterQs = function(xs) {
  return _.filter(function(x) {
    return match(/q/i, x);
  }, xs);
};

// =>
var filterQs = _.filter(match(/q/i));
```

## Chap 5: Coding by Composing
### 函数饲养
> **Composition** feels like function husbandry. You, breeder of functions.(函数饲养员)
```js
var toUpperCase = function(x) {
  return x.toUpperCase();
};
var exclaim = function(x) {
  return x + '!';
};
var shout = compose(exclaim, toUpperCase);

shout("send in the clowns");
//=> "SEND IN THE CLOWNS!"
```
通过left direction, 代理函数的嵌套:

```js
// 结合律（associativity）
var associative = compose(f, compose(g, h)) == compose(compose(f, g), h);
// true
```
> compose 小管道s => 长管道
> 结合律的一大好处是, 函数可任意拆分/组合.

### PointFree
```js
// 非 pointfree，因为提到了数据：word
var snakeCase = function (word) {
  return word.toLowerCase().replace(/\s+/ig, '_');
};

// pointfree
var snakeCase = compose(replace(/\s+/ig, '_'), toLowerCase);
```
> pointfree 模式能够帮助我们减少不必要的命名，让代码保持简洁和通用。
>
> pointfree 是非常好的石蕊试验，因为它能告诉我们一个函数是否是接受输入返回输出的小函数。比如，while 循环是不能组合的。
>
> pointfree 就像是一把双刃剑，不能使用的时候就用普通函数。

### Debug (实用)
> 在管道中的某一点, 输出数据流到这里的Value(是否是后续管道需要的)
```js
var trace = curry(function(tag, x){
  console.log(tag, x);
  return x;
});

var dasherize = compose(join('-'), toLower, trace("after split"), split(' '), replace(/\s{2,}/ig, ' '));
// after split [ 'The', 'world', 'is', 'a', 'vampire' ]
```

### Category theory (范畴学)
在范畴学中，有一个概念叫做...范畴。有着以下这些组件（component）的搜集（collection）就构成了一个范畴：
- objects(对象)的搜集
- morphisms(态射)的搜集
- 态射的组合
- identity 这个独特的态射

#### identity 这个独特的态射
```js
var id = function(x){ return x; };

// id 函数跟组合一起使用简直完美。下面这个特性对所有的一元函数（unary function）（一元函数：只接受一个参数的函数） f 都成立：
// identity
compose(id, f) == compose(f, id) == f;
// true
```
# 组合像一系列管道那样把不同的函数联系在一起，数据就可以也必须在其中流动