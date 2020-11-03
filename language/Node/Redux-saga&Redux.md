###Saga
1. sagas 中的每个函数都必须返回一个 Generator 对象。 middleware 会迭代这个 Generator 并执行所有 yield 后的 Effect.
2. code-splitting应该在routes匹配地方做,异步加载componentContainer、异步注入key.reducer(InitialState)、及sagas的启动.
3. saga有两种其中方式,可以在`createSagaMiddleware`时作为参数传入,或者在middleware传给redux的`createStore`的第二个参数`applyMiddleWare`后,用`run`方法启动.
4. 如何动态关闭saga
5. 子saga应通过`select`来从store中获取keyState.
- 便于维护,且不用层层传递`getState`[http://leonshi.com/redux-saga-in-chinese/docs/api/index.html#selectselector-args]
6. 错误处理: http://leonshi.com/redux-saga-in-chinese/docs/basics/ErrorHandling.html
7. saga*异步操作(Side Effect)*通过组合`Effect`来完成,yield effect 就相当于当一类问题交给一个middleware,比yield Promise方便测试.*
8. saga 在调用 *generator函数*时,会把当前参数传入被调用的*generator函数*

###Redux
1. reducer的第一个参数state,是如何通过`combineReducer`和`state.keyState`对应起来的?
- `createStore(reducer, [preloadedState], [enhancer])`第二个参数,就是`store.state`.
- `combineReducer`,每一个子reducer的`state`,就是store中的`store.key.state`.
- `reducer(previousState, action) => newState`的第一个参数就是其对应`store.key.state`的初始状态.

2.`store`实例有四个方法
- getState()
- dispatch(action)
- subscribe(listener)
- replaceReducer(nextReducer): code-splitting,动态加载reducer需要此API.

3. sagas如何与reducer结合?
- 是否异步加载一个ruducer,就要`run`一个saga,saga来处理异步,完成后调用reducer.
