### Break
`break`, `continue` 只能跳出单层循环,多层需要配合`label`使用

```js
top:
  for (var i = 0; i < 3; i++){
    for (var j = 0; j < 3; j++){
      if (i === 1 && j === 1) break top;
    }
  }
```