### 初识 Nginx

- nginx 指令执行是按 phase 顺序的, 最开始 3 个是`rewrite`, `access` and `content`
  - 而并非`指令`代码的顺序: 必须注意!
  - all `set` commands within `location` are executed in `rewrite` phase
    > https://openresty.org/download/agentzh-nginx-tutorials-en.html#02-nginxdirectiveexecorder01

### Nginx 内如何使用 Lua

- 核心模块, 把 lua 嵌入 ningx: https://github.com/openresty/lua-nginx-module
- nginx docs: http://nginx.org/en/docs/
- nginx dev guide: http://nginx.org/en/docs/dev/development_guide.html
- ningx dev api: https://www.nginx.com/resources/wiki/extending/api/

#### C 动态修改 upstream

- resty 官方, 但不支持 add: https://github.com/openresty/lua-upstream-nginx-module
- 3rd, build 不通过: https://github.com/yzprofile/ngx_http_dyups_module

Todo:

- nginx c moudle 的 build 方式
- nginx 提供了哪些 C API
- lua C 模块的开发
