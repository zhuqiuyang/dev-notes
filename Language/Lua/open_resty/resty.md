### 核心模块

- [lua-nginx-module](https://github.com/openresty/lua-nginx-module)
- [lua-resty-core](https://github.com/openresty/lua-resty-core/)

### data share

- [data share](https://github.com/openresty/lua-nginx-module#data-sharing-within-an-nginx-worker)
  - `lua module`: 单个 worker 内, 不同 request 之间共享.
- [shared.DICT](https://github.com/openresty/lua-nginx-module#ngxshareddic)
  - 多个 worker 之间共享

### Order of Directivess

- [流程图](https://github.com/openresty/lua-nginx-module#directives): 之下

### Timer 与 原生 Context 的数据共享

- 同一进程下, module export 的变量是共享的. (`此次 timer 引用的不是最新数据, 是因为只有worker 0 执行了更新操作.`)

> https://github.com/openresty/lua-nginx-module#ngxtimerat , 末尾有介绍
