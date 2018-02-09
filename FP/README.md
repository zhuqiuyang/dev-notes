# FP
- 更接近声明式(declative)
- 重剑无锋
- 易于流程控制(Promise)
- `function`第一等公民

### 规范及实现
> https://github.com/fantasyland/fantasy-land
> 
> https://github.com/fluture-js/Fluture

# 容器(Functor): 函数使用者(主动权)
## Functor, Monad
- `Monad`是容器
- `Functor`是拥有`map`方法的容器.
- `map`是一个函数, 接受一个函数和`Functor`，我们请求容器来运行这个函数。不夸张地讲，这是一种十分**强大**的理念。
```js
//  map :: Functor f => (a -> b) -> f a -> f b
var map = curry(function(f, any_functor_at_all) {
  return any_functor_at_all.map(f);
});
```

## Cache Result
> 由于实践对性能的要求, 本质问题是数据是否需要重新计算, 还是`one-time` ok. Like编译(一次ok)与解释(运行时决定).

## polymorphism(多态:  OO概念)
- 一个函数可以完成多种`态射`.

# imperative programming(命令式编程)
- method
- procedure (lambda)