### 1. 初识 Nginx

- nginx 指令执行是按 phase 顺序的, 最开始 3 个是`rewrite`, `access` and `content`
  - 而并非`指令`代码的顺序: 必须注意!
  - all `set` commands within `location` are executed in `rewrite` phase
    > https://openresty.org/download/agentzh-nginx-tutorials-en.html#02-nginxdirectiveexecorder01

#### 1.1 Location 匹配:

- `= /uri`: 精确匹配
- `^~`: 前缀匹配(先于正则)
- `~`, `~*` 用于 **正则匹配**:
  - `?<name>`: capture 部分可通过`$name` 变量访问.
- `/uri`: 前缀匹配 (后于正则)
- `/`: default

### 2. Nginx 内如何使用 Lua

- 核心模块, 把 lua 嵌入 ningx: https://github.com/openresty/lua-nginx-module
- [nginx docs](http://nginx.org/en/docs/)
- [nginx dev guide](http://nginx.org/en/docs/dev/development_guide.html)
- [ngx compile module](https://www.nginx.com/resources/wiki/extending/compiling/)
- [ningx dev api](https://www.nginx.com/resources/wiki/extending/api/)
- [nginx C api eg](https://www.nginx.com/resources/wiki/extending/examples/)

### 3. HC, LB, upstream 三者关系

1. health check 要实时获取最新的`ups`, filter 出可用 peer, 传递给`LB`.

#### 3.1 使用 upstream 的利弊

##### 3.1.1 利

- 封装: `upstream`内完成了`health_check, LB`
- 对接简单: `proxy_pass`直接使用`upstream_name`即可.

```conf
upstream foo {
  server 127.0.0.1:8080;
  server 127.0.0.1:8081;

  check interval=3000 rise=1 fall=1 timeout=2000 default_down=true type=http;
  check_http_send "GET / HTTP/1.0\r\n\r\n";
}

server {
    listen 8082;

    location = /test {
        proxy_pass http://foo;
    }
}
```

##### 3.1.2 弊

- 官方模块无法使用, 或功能不满足 (eg: 动态增/删 `upstream`)
  - [nginx 官方 ngx_http_upstream_hc_module](https://nginx.org/en/docs/http/ngx_http_upstream_hc_module.html) 只在**商业版**可用.
  - [openresty 模块](https://github.com/openresty/lua-upstream-nginx-module) 功能欠缺, 不支持`add`等.
- 使用较复杂, `C module`, 需要 `patch 和 build` nginx 代码, 下面列了可用的模块:
  - [ngx_http_dyups_module](https://github.com/yzprofile/ngx_http_dyups_module)
  - [nginx_upstream_check_module](https://github.com/yaoweibin/nginx_upstream_check_module)
  - [nginx_upstream_check_module](https://github.com/yzprofile/nginx_upstream_check_module) (fork 自前者)

### 4. C moudle 开发

- [config_file](https://www.nginx.com/resources/wiki/extending/old_config/)
- [compile module](https://www.nginx.com/resources/wiki/extending/compiling/)
  - [例子](https://github.com/openresty/lua-upstream-nginx-module#installation)

#### 4.1 ngx_foo_module C 代码 (官方例子)

> http://nginx.org/en/docs/dev/development_guide.html
