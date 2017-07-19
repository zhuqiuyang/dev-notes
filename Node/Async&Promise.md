### Async

`async`函数返回的是一个Promise对象.

#### await 命令(http://es6.ruanyifeng.com/#docs/async#await-命令)

- 正常情况下，`await`命令后面是一个 Promise 对象。如果不是，会被转成一个立即`resolve`的 Promise 对象。
- `await`命令后面的 Promise 对象如果变为`reject`状态，则`reject`的参数会被`catch`方法的回调函数接收到。

### Promise

`Promise.resolve`如果参数是Promise实例，那么`Promise.resolve`将不做任何修改、原封不动地返回这个实例。