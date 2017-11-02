### koa & node-fetch

1. 当`ctx.body`是stream时，koa内部直接调用pipe，所以可以直接绕过koa，使用`cres.pipe(ctx.res)`

```js
if (body instanceof Stream) return body.pipe(res);
```

2. node-fetch opts中body字段，可以直接传入`sreq`
   - fetch 返回res的 `res.header.raw()` 对应原生`resp.headers`
   - fetch 返回res的 `res.body` 对应原生的 `resp`
   - fetch 返回res的 `res.status`对应原生 `resp.statusCode`


```js
// fetch 传入的opts字段会直接，传给new Request
const request = new Request(url, opts);
```

3. 在`koa.prototype`上增加 `app.get/post`，在`use`外封装一层。

#### writableStream

koa中ctx.body
node-fetch中request的body

#### readableStream
node-fetch res.body

### 性能提升

![proxy](./wrk_proxy.png)

error record:
```log
3|node-ope |   code: 'ENOTFOUND',
3|node-ope |   errno: 'ENOTFOUND',
3|node-ope |   syscall: 'getaddrinfo',
3|node-ope |   hostname: 'api.shujumohe.com',
3|node-ope |   host: 'api.shujumohe.com',
3|node-ope |   port: 80 } '@@'
3|node-ope | { Error: getaddrinfo ENOTFOUND api.shujumohe.com api.shujumohe.com:80
3|node-ope |     at errnoException (dns.js:50:10)
3|node-ope |     at GetAddrInfoReqWrap.onlookup [as oncomplete] (dns.js:91:26)
3|node-ope |   code: 'ENOTFOUND',
3|node-ope |   errno: 'ENOTFOUND',
3|node-ope |   syscall: 'getaddrinfo',
3|node-ope |   hostname: 'api.shujumohe.com',
3|node-ope |   host: 'api.shujumohe.com',
3|node-ope |   port: 80 } '@@'
```
### promisify can't use in `http.request`?
```js
const requestP = Promise.promisify(http.request);
```
因为 `http.request`会返回一个 `http.clientRequest`实例.

### Koa中间件

- Koa中间件可以是一个 `async`函数或者 返回Promise的普通函数, 是因为`async函数`默认返回的是Promise.

### Compose

koa: 

koa 的`callback`是listen端口是传入的callback

```js
  callback() {
    const fn = compose(this.middleware);

    if (!this.listeners('error').length) this.on('error', this.onerror);

    const handleRequest = (req, res) => {
      res.statusCode = 404;
      const ctx = this.createContext(req, res);
      const onerror = err => ctx.onerror(err);
      const handleResponse = () => respond(ctx);
      onFinished(res, onerror);
      return fn(ctx).then(handleResponse).catch(onerror);
    };

    return handleRequest;
  }
```



koa-compose: 

```js
function compose (middleware) {
// ... 删除了异常检测代码
  return function (context, next) {
    // last called middleware #
    let index = -1
    return dispatch(0)
    function dispatch (i) {
      if (i <= index) return Promise.reject(new Error('next() called multiple times'))
      index = i
      let fn = middleware[i]
      // 此处 next 传入的是undefined, 此时代表最后一个中间件
      // 调用了next()方法, 返回 Promise.resolve()
      if (i === middleware.length) fn = next
      if (!fn) return Promise.resolve()
      try {
        return Promise.resolve(fn(context, function next () {
          return dispatch(i + 1)
        }))
      } catch (err) {
        return Promise.reject(err)
      }
    }
  }
}
```

### Koa
1. koa ctx.url use for url rewrite.
2. set path会先parse; set url 直接设置 ctx.req.url

#### app.keys = []
> Set signed cookie keys, based on `KeyGrip`.
1. Keys is array, Key优先级是从高到底的, 这样新Key在对前插入, `old digest`校验index不等于0, 则重新赋值.