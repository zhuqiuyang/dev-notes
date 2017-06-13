###Universal Router
1. resolve的第二个参数是一个或多个任意数值类型,会作为一个Object传递给routes中定义的action方法.此Object在传给action后,会附加一些额外属性,
- `params`命中RESTFul的字段
- `next`用于继续传入匹配的子router

2. action 会一级一级向下遍历匹配的children中的action.
3. action可以调用传入`Object.next`作为中间件来使用.

###须知
1. *server.js* 中`import assets from './assets'`,是因为build后两文件同在一个目录下.
2. SSR的模板是*Html*组件
3. Set数据结构类似数组,无重复数值.

###RSK
1. client.js打包后 => *build/public/assets/main.[hash].js*
2. server.js SSR打包后的包时,通过
```
new AssetsPlugin({
      path: path.resolve(__dirname, '../build'),
      filename: 'assets.js',
      processOutput: x => `module.exports = ${JSON.stringify(x)};`,
    }),
```
来在server.js中 调用assets.main.js调用打包后的文件.
由于是SSR,client端引用`/assets/main.js`就是对应`build/public/`目录下.
*由于RSK没指定chunk name,所以默认chunk name 是 main*

###答疑:
1. ouput.filename中的*[name]*,指的是chunkname,而不是文件name.
2. 官方 multi-conpiler example: https://github.com/webpack/webpack/tree/master/examples/multi-compiler
