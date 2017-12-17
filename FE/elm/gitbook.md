## Core language
- values
- list (array)
- tuple ()
  > A tuple can hold a fixed number of values, and each value can have any type.
- records (object)
### Comparing Records and Objects

Records in Elm are similar to objects in JavaScript, but there are some crucial differences. The major differences are that with records:

- You cannot ask for a field that does not exist.
- No field will ever be undefined or null.
- You cannot create recursive records with a this or self keyword.
`Elm encourages a strict separation of data and logic`, and the ability to say this is primarily used to break this separation. This is a systemic problem in Object Oriented languages that Elm is purposely avoiding.

## Architecture
### The Basic Pattern

The logic of every Elm program will break up into three cleanly separated parts:

- Model — the `state` of your application (pure state)
- Update — a way to update your state (`action handler`)
- View — a way to view your state as HTML

## User input
### buttons
```elm
view model =
  div []
    [ button [ onClick Decrement ] [ text "-" ]
    , div [] [ text (toString model) ]
    , button [ onClick Increment ] [ text "+" ]
    ] 
```
div` and `button` are normal Elm functions. These functions take
1. a list of attributes 
2. a list of child nodes.
**Since we are using normal Elm functions, we have the full power of the Elm programming language to help us build our views!**

**The view code is entirely declarative.** (要展示什么, 而不关注如何操作DOM)
We take in a Model and produce some Html, That is it.

## Effect
- Commands — A Cmd lets you do stuff: generate a random number, send an HTTP request, etc.
- Subscriptions — A Sub lets you register that you are interested in something: tell me about location changes, listen for web socket messages, etc.
### Random
- 难点1: Union Type(下有, 底层如何实现的?)
  ```elm
  type Msg
    = Roll
    | NewFace Int
  ```

### HTTP

> Result(*)
```elm
type Result error value
  = Err error
  | Ok value

(Result Http.Error String)
```
means: 



## Type
> Type Inference (elm compiler可以check出拼写或类型错误)

### Reading Type
#### primitives
- Number (Int, Float)
- String
- Char
- Bool

#### Functions
- Between the `backslash` and the `arrow`, you list the arguments of the function:
> 函数的参数在`\`和 `->`中间
- anonymouse Functions
  ```elm
  \n -> n / 2
  <function> : Float -> Float
  (\n -> n / 2) 128
  64 : Float
  ```
- all of following named styles are equivalent:
  ```elm
  > divide x y = x / y
  > divide x = \y -> x / y
  > divide = \x -> (\y -> x / y)
  <function> : Float -> Float -> Float
  ```
`Float -> Float -> Float` 实际是  `Float -> (Float -> Float)`

### Type alias
> alias 全是为了易于阅读.
- `type alias` 为新的数据类型起alias

### Union Type
> Note: Union types are sometimes called `tagged unions`. Some communities call them `ADTs`.
```elm
> type User = Anonymous | Named String

> Anonymous
Anonymous : User

> Named
<function> : String -> User
```
`Named` is a function `String -> User` (*难点)