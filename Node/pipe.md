### koa & node-fetch
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
