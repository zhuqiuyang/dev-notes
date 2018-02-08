1. main
   > 必须从 main 开始

* 无参数
* 无`return`

2. 函数

不定量参数支持

```go
 func myfunc(arg ...int) {}
```

3. 方法的定义

```go
func (r *Rectangle) area() float64 {
l := distance(r.x1, r.y1, r.x1, r.y2) w := distance(r.x1, r.y1, r.x2, r.y1) returnl*w
}
```

4. 接口
   > `struct`定义 field, `interface`定义 method 集合

```go
type Shape interface { area() float64
}
```

5. package

目的:

* eg, 使用`fmt`, 当程序更改, 不需要每次 recompile `fmt` package

```go
package main
import ( "fmt"
"io/ioutil"
)
func main() {
bs, err := ioutil.ReadFile("test.txt") iferr!=nil{
return
}
str := string(bs)
        fmt.Println(str)
    }
```

6. Test
