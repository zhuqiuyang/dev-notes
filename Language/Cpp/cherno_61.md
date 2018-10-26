### 62.Threads in C++

> eg: wait input, do something else.

```cpp
// 接收一个function pointer
std::thread worker(DoWork);

// wait the work finish (block)
worker.join();
```

eg: Dowork, until type `Enter`:
