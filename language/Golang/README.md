### 个人经验

#### 提高性能, async 调用其内部使用 channel 即可

> eg, mysql 查询

#### sync

- Package `sync` 类似 mutual exclusion locks(互斥锁)的 同步 primitive.
- Other than the Once and WaitGroup types, most are intended for use by **low-level** library routines.
- **Higher-level** 的 sync 最好使用 channels and communication 来实现.

#### range channel

The loop for `i := range c` 重复地从`c`channel 中取值, 直到其被`close`.

可以`close`一个非空的`channel`, 再其值取完后, 会自动`close`.

```go
package main
import "fmt"
func main() {

    queue := make(chan string, 2)
    queue <- "one"
    queue <- "two"
    close(queue)

    for elem := range queue {
        fmt.Println(elem)
    }
}
```

### :=

- 左侧至少有一个新变量即可.

```go
var i = 1
i, err := 2, true
```

- 会 shadow 全局变量 (**注意**)

> https://nanxiao.gitbooks.io/golang-101-hacks/content/posts/short-variable-declarations.html

### Slice

> https://blog.golang.org/go-slices-usage-and-internals

```go
// create slice
letters := []string{"a", "b", "c", "d"}
s := make([]byte, 5)

// copy
t := make([]byte, len(s), (cap(s)+1)*2)
copy(t, s)
s = t

// append
a := make([]int, 1)
// a == []int{0}
a = append(a, 1, 2, 3)
// a == []int{0, 1, 2, 3}
```

- 解决指向 array 过大, 无法回收的问题

```go
func CopyDigits(filename string) []byte {
    b, _ := ioutil.ReadFile(filename)
    b = digitRegexp.Find(b)
    // 开辟新空间, 只有需要的大小
    c := make([]byte, len(b))
    copy(c, b)
    return c
}

// append 版本?
c := []byte
append(c, b...)
```
