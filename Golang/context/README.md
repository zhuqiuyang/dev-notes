### blog 例子:

> 做到了 goroutine 间安全使用

- `userip`: 提供为其他两个 package 提供新的 ctx
  - `server.go`: 插入 userip
  - `google.go`: 提取用户 ip
