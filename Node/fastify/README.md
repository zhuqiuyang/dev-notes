### Fastify

#### 0. Get start

```sh
└── plugins (from the Fastify ecosystem)
└── your plugins (your custom plugins)
└── decorators
└── hooks and middlewares
└── your services
```

#### 1. JSON validate (\*)

#### 2. Router (\*)

* no Regx
* no closure allocation

#### 3. plugin(register) (\*)

> As in JavaScript everything is an object, in Fastify everything is a plugin.
>
> https://github.com/fastify/fastify/blob/master/docs/Plugins-Guide.md

* 增加一个 plugin, 唯一个 API `register`

源码阅读:

* `fastify.register`是`avvio.use`
* `fastify.use`是使用的其内部`use`函数

```js
fastify.register(require('./my-plugin'), { options });
```

* 通过`fastify-plugin`包装一个 `plugin function` exposes the decorators, hooks, and middlewares declared inside the plugin to the parent scope.
* Plugin loading starts when you call `fastify.listen()`, `fastify.inject()` or `fastify.ready()`

#### 4. Routes

> https://github.com/fastify/fastify/blob/master/docs/Routes.md

#### 4. docorate

`decorate` 是唯一能扩展 server functionalities 的`API`, you can also use `decorateRequest` and `decorateReply`.

在 root scope 声明, 两种方式:

* 直接在 Root Scope 声明, 这样其 子 scope 都可以访问到.
* `fastify-plugin` 提升一层

#### 5. Request

The first parameter of the handler function is `Request`.<br>
Request is a core Fastify object containing the following fields:

* `query` - the parsed querystring
* `body` - the body
* `params` - the params matching the URL
* `headers` - the headers
* `raw` - the incoming HTTP request from Node core _(you can use the alias `req`)_
* `id` - the request id
* `log` - the logger instance of the incoming request

```js
fastify.post('/:params', options, function(request, reply) {
  console.log(request.body);
  console.log(request.query);
  console.log(request.params);
  console.log(request.headers);
  console.log(request.raw);
  console.log(request.id);
  request.log.info('some info');
});
```

#### 6. Reply

> https://github.com/fastify/fastify/blob/master/docs/Reply.md

The second parameter of the handler function is `Reply`.
Reply is a core Fastify object that exposes the following functions:

* `.code(statusCode)` - Sets the status code.
* `.header(name, value)` - Sets a response header.
* `.getHeader(name)` - Retrieve value of already set header.
* `.hasHeader(name)` = Determine if a header has been set.
* `.type(value)` - Sets the header `Content-Type`.
* `.redirect([code,] url)` - Redirect to the specified url, the status code is optional (default to `302`).
* `.serialize(payload)` - Serializes the specified payload using the default json serializer and returns the serialized payload.
* `.serializer(function)` - Sets a custom serializer for the payload.
* `.send(payload)` - Sends the payload to the user, could be a plain text, a buffer, JSON, stream, or an Error object.
* `.sent` - A boolean value that you can use if you need to know if `send` has already been called.
* `.res` - The [`http.ServerResponse`](https://nodejs.org/dist/latest/docs/api/http.html#http_class_http_serverresponse) from Node core.

#### 7. mw

> https://github.com/fastify/fastify/blob/master/docs/Middlewares.md

#### 8. Hooks

关闭应用前, 关闭 db 连接

```js
fastify.addHook('onClose', (instance, done) => {
  // some code
  done();
});
```
