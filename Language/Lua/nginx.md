### 1. 初识 Nginx

- nginx 指令执行是按 phase 顺序的, 最开始 3 个是`rewrite`, `access` and `content`
  - 而并非`指令`代码的顺序: 必须注意!
  - all `set` commands within `location` are executed in `rewrite` phase
    > https://openresty.org/download/agentzh-nginx-tutorials-en.html#02-nginxdirectiveexecorder01

#### 1.1 Location:

```text
Syntax:	location [ = | ~ | ~* | ^~ ] uri { ... }
location @name { ... }
Default:	—
Context:	server, location
```

##### 1.1.1 匹配顺序

- `= /uri`: 精确匹配
- `^~`: 前缀匹配(`^`regx 含义是匹配开头; `^~`表示`先于正则`?)
- `~`: 表示 **正则匹配** (`~*`不区分大小写)
  - `?<name>`: capture 部分可通过`$name` 变量访问.
- `/uri`: 前缀匹配 (后于正则)
- `/`: default

##### 1.1.2 实战(根据 APP_NAME 转发)

推导:

1. 匹配`app_name`只能通过正则(顺序第三)

所以:

1. 重要, 可能重叠的匹配, 尽量使用`=` 或 `^~`(先于正则)

其他方案:

1. 匹配不到转发到, `proxy_pass`到其他服务端口.
2. `^~ /`: 匹配所有服务, 内部做正则
3. `@name`: named location 代替`proxy_pass`跳转?(**优先考虑**)

#### 1.1.3 Named Location

> http://nginx.org/en/docs/http/ngx_http_core_module.html

用途:

- 用作 `request redirection`

局限:

- 不能嵌套
- 不能包含其他`location`

```conf
location @fallback {
  internal;
  proxy_pass http://backend;
}
```

#### 1.2 ngx_http_rewrite_module module

- `break`: 继续在当前`location`处理请求, 但停止`ngx_http_rewrite_module`下的所有`directive`.
- `return`: 返回`code` 到 client 端, 停止处理请求.
- `rewrite` flag:
  - `last`: 停止在当前 set 处理请求, 对新的 URL 开始新一轮匹配.
  - `break`: 同上`break`
  - `redirect`: 302 返回给 client

```conf
server {
    listen 8080;
    # 此处 break 会停止执行 server 块的 return 指令(return 指令属于rewrite模块)
    # 如果把它注释掉 则所有请求进来都返回 ok
    break;
    return 200 "ok";
    location = /testbreak {
        break;
        return 200 $request_uri;
        proxy_pass http://127.0.0.1:8080/other;
    }
    location / {
        return 200 $request_uri;
    }
}

# 发送请求如下
# curl 127.0.0.1:8080/testbreak
# /other

# 可以看到 返回 `/other` 而不是 `/testbreak`，说明 `proxy_pass` 指令还是被执行了
# 也就是说 其他模块的指令是不会被 break 中断执行的
# (proxy_pass是ngx_http_proxy_module的指令)
```

#### 1.3 pass_proxy

1. 何时`截断`前缀匹配:

- `proxy_pass: host:port/;` url 后增加`/`即可 (`/ ^~` 皆可用)

### 2. Nginx 内如何使用 Lua

- 核心模块, 把 lua 嵌入 ningx: https://github.com/openresty/lua-nginx-module
- [nginx docs](http://nginx.org/en/docs/)
- [nginx dev guide](http://nginx.org/en/docs/dev/development_guide.html)
- [ngx compile module](https://www.nginx.com/resources/wiki/extending/compiling/)
- [ningx dev api](https://www.nginx.com/resources/wiki/extending/api/)
- [nginx C api eg](https://www.nginx.com/resources/wiki/extending/examples/)

#### 2.1

- [lua_package_path](https://github.com/openresty/lua-nginx-module#lua_package_path)
  - [$prefix 介绍](http://openresty.org/en/installation.html)

### 3. HC, LB, upstream 三者关系

1. `ups`(实时) -> `hc` -> `LB`.

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

#### 3.2 实战解决

##### 3.2.1 upstream 变量获取

- 通过[ngx.var.VARIABLE](https://github.com/openresty/lua-nginx-module#ngxvarvariable)获取 `upstream` 变量

```conf
# dyups 要求, 传入 nginx 变量即可
# 测试传入 upstream_name 对应的 字符串 即可.
set $ups upstream_name;
proxy_pass http://$ups;

# 当 upstream_name 存于 变量中时, 需要

set_by_lua_block $ups {
    return ngx.var[1] -- 获取 upstream 变量
}
```

### 4. C moudle 开发

- [config_file](https://www.nginx.com/resources/wiki/extending/old_config/)
- [compile module](https://www.nginx.com/resources/wiki/extending/compiling/)
  - [例子](https://github.com/openresty/lua-upstream-nginx-module#installation)

#### 4.1 ngx_foo_module C 代码 (官方例子)

> http://nginx.org/en/docs/dev/development_guide.html

### 5. 纯 lua 开发

#### 5.1 方案

- 舍弃`upstream`, 直接`proxy_pass: http://host:port`使用
  - 更直接, 不需要对`upstream` name 再做域名映射, 也不需要`set_current_peer`
  - [ngx.balance](https://github.com/openresty/lua-resty-core/blob/master/lib/ngx/balancer.md)只具备在`upstream`内指定`host/port`的功能, `LB`要自己做

```conf
upstream foo {
  # server 127.0.0.1:8080;

  # 不使用 server; hc, LB 需自实现
  local balancer = require "ngx.balancer"
  local ok, err = balancer.set_current_peer(host, port)
}
```

- 所以`ups`, `hc`, `LB`全部要自己开发:
  - `ups` 通过`shared.DICT`
  - `hc`过滤出可用`addr` -> `LB` (\*)
- 结合了`hc`和`LB`的两个模块
  - https://github.com/hamishforbes/lua-resty-upstream
    - `connect`
  - [upyun-checkups](https://github.com/upyun/lua-resty-checkups)
    > 功能完整, 可以使用
    - `select_peer`
- 纯 hc
  - https://github.com/Kong/lua-resty-healthcheck
