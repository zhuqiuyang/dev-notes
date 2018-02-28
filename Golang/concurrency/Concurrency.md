### 并发模型 Go vs Node

* Node 是通过发布/订阅来进行事件通知.(单线程中, 无锁的概念)
* 而 Go 是通过 channel 来在多 Goroutine 之间传递消息,更灵活. (内部多线程, 有锁的概念)

### Share mem by Communicate

> https://blog.golang.org/share-memory-by-communicating
>
> CodeWalk: https://golang.org/doc/codewalk/sharemem/

传统的并发模型(JAVA, C++, Python), 是通过 share memory, 并通过 Lock 来控制访问.
Go 提倡使用 channel 在 goroutines 间传递 the ref of data.
这样确保, 同一时间, 只有一个 goroutine 可以访问数据.

### FAQ

1. goroutine 如何关闭, 在`urlpoll.go` 的 `StateMonitor`函数中使用了 pipeline.
> 进程退出才会关闭, 函数调用完成并不会? 