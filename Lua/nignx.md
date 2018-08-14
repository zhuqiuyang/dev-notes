- nginx 指令执行是按 phase 顺序的, 最开始 3 个是`rewrite`, `access` and `content`
  - 而并非`指令`代码的顺序: 必须注意!
  - all `set` commands within `location` are executed in `rewrite` phase
    > https://openresty.org/download/agentzh-nginx-tutorials-en.html#02-nginxdirectiveexecorder01
