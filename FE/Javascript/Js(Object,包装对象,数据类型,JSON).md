##Js深入理解(Object、包装对象、数据类型、JSON)
### 2.基本语法-2.1概述-4.数据类型[http://javascript.ruanyifeng.com/grammar/basic.html#toc17]
	1. 概述JavaScript的数据类型，共有六种。（ES6又新增了第七种Symbol类型）
	- (img)、(img)
	2. typeof运算符
	- JavaScript有三种方法，可以确定一个值到底是什么类型。(`typeof`运算符,`instanceof`运算符[http://javascript.ruanyifeng.com/oop/basic.html#toc5](img),`Object.prototype.toString`方法)
	- typeof运算符可以返回一个值的数据类型
		- 原始类型(`number`、`string`、`boolean`)
		- function(函数两种定义方法 都相同)
		- `undefined`(未定义 或者 初始化就为undefined)
		- 除上述,都是`object`.((img):null也是object,历史原因; array和object 用instanceof运算符判断.)

###正则表达式理解难点
1. 非贪婪匹配中(满足即可):
- `*?`:代表匹配0次即可,所以是没有意义的.**个人当前理解**
- `+?`:和量词1是同等的,只匹配一次.
- `\w`:匹配任意的字母、数字和下划线,相当于[A-Za-z0-9_]
- `\d`:匹配0-9之间的任一数字,相当于[0-9].
- `.`:匹配除回车（\r）、换行(\n) 、行分隔符（\u2028）和段分隔符（\u2029）以外的*所有字符*。
- 转义字符:(img)

###固定this的方法[http://javascript.ruanyifeng.com/oop/basic.html#toc10](JavaScript提供了call、apply、bind这三个方法)
- call:绑定this指向,并调用原函数.
- apply:与call唯一不同,接收参数为一个*数组*.
- bind:绑定this指向,返回一个新的函数.
- **本质:指定*上级(上下文)*及参数..**
- eg: (img) `var slice = Function.prototype.call.bind(Array.prototype.slice);`(slice 等同于`Array.prototype.slice.call`,这里`Array.prototype.slice`是`.call`的*上级*;新生产的slice再为`Array.prototype.slice`方法指定*上级*并传入其运行所需要的参数.)
- eg:`var bind = Function.prototype.call.bind(Function.prototype.bind);`(此时bind的作用是为`.bind`指定*上级*,并为`.bind`传入参数,即再为`.bind`的*上级*:bind中传入的第一个参数,所调函数;指定*上级*:bind中第二个参数.)[https://variadic.me/posts/2013-10-22-bind-call-and-apply-in-javascript.html]

###Object对象
1. 概述
- (img)(Object作为__构造函数__使用时,可以接受一个参数。_对象_,返回这个_对象_;_原始类型_,返回对应的_包装对象_)
- 部署方法(img)
2. Object对象的方法
	1. Object(作为__工具方法__ 使用时,可以将任意值转为对象。其中，原始类型的值转为对应的包装对象)
	2. 遍历对象的属性
	-  一般用来遍历对象的属性,是对象自身的(而_不是继承_的)所有属性名.(下两者都是接收一个对象,返回一个数组)
		- `Object.keys()`方法只返回可枚举的属性
		- `Object.getOwnPropertyNames()`方法还返回不可枚举的属性名。
	- Object.observe(太新,暂时用不到)(img)
3. Object实例对象的方法
__不可枚举,是指在枚举某个对象的属性时,对应属性不计算在内.__
4. 对象的属性模型

###包装对象和Boolean对象[http://javascript.ruanyifeng.com/stdlib/wrapper.html]
1. 包装对象
	1. 定义:(img)
	2. 包装对象的构造方法:Number、String和Boolean，既可以当作_构造函数_使用,也可以当作_工具方法_使用.(img)
	3. 包装对象实例的方法(img)
	- valueOf()
	- toString()
	4. 原始类型的自动转换(img)
	5. 自定义方法(_可以加在对象上,但不能在原始类型上_)(img)
2. Boolean对象
	1. 概述(img)
	2. Boolean实例对象的布尔值(所有对象的布尔运算结果都是`true`)

###JSON对象[http://javascript.ruanyifeng.com/stdlib/json.html]
1. JSON格式:(img)(和对象的区别:(img))
2. JSON对象:
- ES5新增了JSON对象，用来处理JSON格式数据。它有两个方法：`JSON.stringify`:把JSON转成字符串;`JSON.parse`把字符串转成JSON.

###数组对象
1. `Array.prototype.map()`依次遍历每个元素,另返回一个新数组.
- (img)(map方法接_收一个函数作为参数_,并为其传入三个参数)
2. `Array.prototype.forEach()`,只操作元素,无返回值.
3. `slice()`:提取原数组的一部分,返回一个新数组.接收参数为元素位置,默认为0到结尾.

###String对象
- `trim()`:去除数组两边空格,返回一个新的字符串,不改变原字符串.
