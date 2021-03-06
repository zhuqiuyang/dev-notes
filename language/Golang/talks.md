### LearnConcurrency

> https://github.com/golang/go/wiki/LearnConcurrency

## 2012: Concurrency is not parallelism:

https://talks.golang.org/2012/waza.slide

## Google IO 2013 - Advanced Go Concurrency Patterns:

https://talks.golang.org/2013/advconc.slide#8

### Goroutines and Channels

> Goroutines are independently executing fuctions in the same address space.

## Google IO 2012 - Go Concurrency Patterns

https://www.youtube.com/watch?v=f6kdp27TYZs
slides: https://talks.golang.org/2012/concurrency.slide#40

### Channels

A channel in go provides a connection between two goroutines, allowing them to communicate.

```go
// Declaring and initializing
var c chan int
c = make(chan int)
//or
c := make (chan int)

//Sending on a channel
c <- 1

//Receiving from a channel
// The "arrow" indicates the direction of data flow
value = <-c
```

### Synchroization

### The Go approach

Don't communicate by sharing memory, share memory by communicating.
_go routine, can only communicate through channel , cannot share one variable in one function._

### Generator: function that returns a channel

### Channels as a handle on a Service

Our boring function returns a channel that lets us communicate with the boring service it provides.

### Multiplexing

![屏幕快照 2017-02-13 下午2.28.22.png](quiver-image-url/8CC1A33611529C9EE936252C33A2802E.png)

### Select

A control structure unique to concurrency.

The select statement provides another way to handle multiple channels.
It's like a switch, but each case is a communication:

### Timeout using select

The `time.After` function returns a channel that blocks for the specified duration. After the interval, the channel delivers the current time, once.

```go
func main() {
	c := boring("Joe")
	for {
		select {
		case s := <-c:
			fmt.Println(s)
		case <-time.After(1 * time.Second):
			fmt.Println("You're too slow.")
			return
		}
	}
}
```

### Timeout for whole convensation using select

```go
func main() {
	c := boring("Joe")
	timeout := time.After(5 * time.Second)
	for {
		select {
		case s := <-c:
			fmt.Println(s)
		case <-timeout:
			fmt.Println("You talk too much.")
			return
		}
	}
}
```

### Daisy-chain

* 代码对应模型图: leftmost <- right(0) ... right(n-1)
* right 从最左端一直往右移, left 也如此.

### Systems software

Go was designed for writing systems software.

### Conclusion

Goroutines and channels make it easy to express complex operations dealing with:

* multiple inputs
* multiple outputs
* timeouts
* failure
