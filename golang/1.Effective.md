###一.nameing
1. 包名, 目录名即packge名.
>函数外的每个语句都必须以关键字开始（ var 、 func 、等等）， := 结构不能使用在函数外。

2. 获取器:
```go
//owner 字段的获取器为 Owner.
//设置器 为SetOwner
owner := obj.Owner()
if owner != user {
	obj.SetOwner(user)
}
```

3. 接口名: 只包含一个方法的接口通过-er后缀来命名.
4. camelCase

###二.formating

###三.program construction

## reflection ,interface, Goroutine,
2. https://golang.org/doc/effective_go.html
