# Dev-notes
Dev Learning Notes

## Term
### Pipe
```elixir
host
|> Store.get_host
|> to_map
|> tabularize
|> IO.puts
```
### Pattern Macthing
> pc: 一个函数重载多次, 且能相互递归调用. (负责度`log(n)`, 少了`if else`), 类似于key->value match.
>
> eg: elixir: https://zhuanlan.zhihu.com/p/19968376

### ADT
union type (elm)

### FP
> PC: `string.length`(OO实现), FP实现是定义一个`getLength` 函数, 可作用于所有`String`?
#### category(范畴)
> 点(成员)和箭头(morphism)的集合
> 
> C++中重载是多态的一种.
>
> 函数, 管道, 无状态

#### Functor(函子)
> an opertor or function.
> 一般约定，函子的标志就是容器具有`map`方法。该方法将容器里面的每一个值，映射到另一个容器。

> 学习函数式编程，实际上就是学习函子的各种运算
- Functor 代码实现
```js
class Functor {
  constructor(val) { 
    this.val = val; 
  }

  map(f) {
    return new Functor(f(this.val));
  }
}
```
#### of
replace `new` to generate new Functor
```js
Functor.of = function(val) {
  return new Functor(val);
};
```

#### Maybe (functor)
> pc: 解决无数据 函数报错.
```js
class Maybe extends Functor {
  map(f) {
    return this.val ? Maybe.of(f(this.val)) : Maybe.of(null);
  }
}
```
#### Either (functor)
用途(处理分支场景):
- `if...else`在FP的表达
- 代替`try...catch`，使用左值表示错误。
Either 函子内部有两个值：左值（Left）和右值（Right）。右值是正常情况下使用的值，左值是右值不存在时使用的默认值。
```js
class Either extends Functor {
  constructor(left, right) {
    this.left = left;
    this.right = right;
  }

  map(f) {
    return this.right ? 
      Either.of(this.left, f(this.right)) :
      Either.of(f(this.left), this.right);
  }
}

Either.of = function (left, right) {
  return new Either(left, right);
};
```
#### ap (functor)
```js
function add(x) {
  return function (y) {
    return x + y;
  };
}

Ap.of(add).ap(Maybe.of(2)).ap(Maybe.of(3));
// Ap(5)
```
> ap 函子的意义在于，对于那些多参数的函数，就可以从多个容器之中取值，实现函子的链式操作。

#### Monad (functor)
- 数据包含`值`和`type`(使用的context)
> Monad就是一种设计模式，表示将一个运算过程，通过函数拆解成互相连接的多个步骤。 (http://www.ruanyifeng.com/blog/2015/07/monad.html?utm_source=tuicool)
#### I/O 操作
Monad 函子的重要应用，就是实现 I/O （输入输出）操作。