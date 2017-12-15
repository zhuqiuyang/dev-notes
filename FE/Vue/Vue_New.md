```javascript
new Vue({
  el: '#app',
  router,
  store,
  template: '<App/>',
  components: { App }
})
// el挂载的DOM节点, 用template中内容替换#app
// router, store 都是传入的实例.
// components 包含 Vue 实例可用组件的哈希表。
```
