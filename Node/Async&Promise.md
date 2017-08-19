### Async

#### Essence

进一步说，`async`函数完全可以看作多个异步操作，包装成的一个 Promise 对象，而`await`命令就是内部`then`命令的语法糖。 (es6.ruanyifeng.com)

`async`函数返回的是一个Promise对象及状态改变:

- `async`函数返回的 Promise 对象，必须等到内部所有`await`命令后面的 Promise 对象执行完，才会发生状态改变，除非遇到`return`语句或者抛出错误。

#### await 命令(http://es6.ruanyifeng.com/#docs/async#await-命令)

- 正常情况下，`await`命令后面是一个 Promise 对象。如果不是，会被转成一个立即`resolve`的 Promise 对象。
- `await`命令后面的 Promise 对象如果变为`reject`状态，则`reject`的参数会被`catch`方法的回调函数接收到。

### Promise

`Promise.resolve`如果参数是Promise实例，那么`Promise.resolve`将不做任何修改、原封不动地返回这个实例。