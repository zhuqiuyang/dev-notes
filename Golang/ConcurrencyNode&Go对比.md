### 并发模型Go vs Node
- Node是通过发布/订阅来进行事件通知.(单线程中, 无锁的概念)
- 而Go是通过channel来在多Goroutine之间传递消息,更灵活. (内部多线程, 有锁的概念)
