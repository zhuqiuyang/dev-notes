### 场景 1: 固定间隔 + 判断是否继续执行

```js
async ASYNC_TIME_OUT({ rootState, dispatch }) {
    const interval = ms => {
      // 1. 初始
      dispatch('ASYNC_XXX')
      // 2. 设置 interval 之后, 是否继续
      setTimeout(() => {
        if (rootState.route.name === 'xxx') {
          interval()
        }
      }, ms)
    }
    interval(3000)
  }
```
