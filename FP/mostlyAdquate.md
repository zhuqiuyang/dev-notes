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
