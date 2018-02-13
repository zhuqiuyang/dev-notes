### 2012: Go at Google: Language Design in the Service of Software Engineering

> https://talks.golang.org/2012/splash.article

> The **goals** of the Go project were to eliminate the slowness and clumsiness of software development at Google, and thereby to make the process more productive and scalable. The language was designed by and for people who write—and read and debug and maintain—large software systems.
>
> Go's **purpose** is therefore not to do research into programming language design; it is to improve the working environment for its designers and their coworkers. Go is more about software engineering than programming language research. Or to rephrase, it is about language design in the service of software engineering.

个人理解: Method 不在 struct 中定义, 便于代码分离

### 13. Concurrency

#### CSP 适合于 procedual language

> Go embodies a variant of CSP with first-class channels.

> Don't communicate by sharing memory, share memory by communicating.

### 14. Garbage collection

> Of course, garbage collection brings significant costs: general overhead, latency, and complexity of the implementation. Nonetheless, we believe that the benefits, which are mostly felt by the programmer, outweigh the costs, which are largely borne by the language implementer.

```go
type X struct {
    a, b, c int
    buf [256]byte
}
```

* In Go, the buffer is allocated in a `single block` of memory along with the containing struct and no indirection is required.
* in Go it is easy and efficient to provide `second-order allocators`
* that use of `interior pointers` can have a significant effect on total arena size, latency, and collection times.

总之, go 是一门使用了 GC 的语言,但仍赐予 programmer 一些控制 collector 的手段.
