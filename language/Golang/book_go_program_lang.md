#### 8.5 loop in parallel

疑惑: `makeThumbnails4`例子中的`goroutine leak`问题, lock 的 goroutine 不会在主函数退出而关闭吗?

`makeThumbnail5`中通过一个 buffered channel,防止了 **goroutine locked**.
