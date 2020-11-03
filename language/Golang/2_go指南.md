1. https://tour.go-zh.org
2. 没有条件的switch相当于 更清晰的else链.
3. defer
- defer 语句会延迟函数的执行直到上层函数返回。
- 延迟调用的参数会立刻生成，但是在上层函数返回前函数都不会被调用。

4. go的结构体指针访问是透明的.

5. 方法: (Receiver可以是指针或者值传递)
```go
func (r ReceiverType) funcName(parameters) (results)
```
