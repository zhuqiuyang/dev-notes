### 个人经验

#### 提高性能, async 调用其内部使用 channel 即可

> eg, mysql 查询

#### sync

* Package `sync` 类似 mutual exclusion locks(互斥锁)的 同步 primitive.
* Other than the Once and WaitGroup types, most are intended for use by **low-level** library routines.
* **Higher-level** 的 sync 最好使用 channels and communication 来实现.

#### range channel

The loop for `i := range c` 重复地从`c`channel 中取值, 直到其被`close`.
