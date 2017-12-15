##ES6 [http://caibaojian.com/es6.html];[https://babeljs.io/docs/learn-es2015/]
1. 箭头函数(img)
- 如果返回一个*对象*,要用`()`包裹起来.(img)
- 使用注意:(img)
- pipeline机制:(Babel测试:(img))
- 函数绑定(img)

2. Classes(ES6引入了`class`可以看做是一个语法糖,它的绝大部分功能,es5都能做到,但写法更清晰.)
	1. 基本语法
	- 类内部定义的所有方法都是不可枚举的:(img)
	- `constructor`是默认方法,必须添加,默认为空.
	- _类的实例对象_:使用`new`关键字实例化,与ES5一样，实例的属性除非显式定义在其本身（即定义在this对象上），否则都是定义在原型上（即定义在class上）。(eg-> (img))
	- class表达式:(img)
	- **不存在hoist**,class必须先定义,再使用(img)
	- 严格模式:(img)

	2. Class的集成:通过`extentd`实现
	- `extends` 继承
		- 子类必须在`consrtuctor`方法中调用`super`方法,因为子类中没有`this`,必须继承父类的`this`,构造新的构造方法:(img)
	- `Extends 的继承目标`:(img)(有prototype属性皆可继承,包括任何函数.)
	- `super`关键字两种用法(img)(1.作为函数,代表父构造函数 2.作为对象,代表父类) _且由于对象总是继承自其他对象,所以可以在任意一个对象中，使用super关键字._

	4. Class的get和set(img)(用对_拦截_存储行为)
	5. Class的Generator方法->(img)(某个方法前加上`*`)
	6. Class的静态方法
	- 方法前加上`static`,不能被实例继承,只能通过类进行调用.(包括子类)
	7. Class的静态属性和实例属性:
	- 静态属性:(img)(静态属性ES6支持一种写法,且ES规定,__Class内只能有静态方法,不能有静态属性__)
	- 但Babel有**很方便**的Class静态属性和实例属性的新写法:
		- 类的实例属性:(img),
		- 类的静态属性:(img)(只要在实例属性前加上static即可)
	8. new.target属性(用于判断构造函数是否通过`new`关键字调用)
	- 特点:(img)(利用这个特点,可以写出必须继承后才能使用的类->(img))
		- Class内部调用new.target，返回当前Class
		- 子类继承父类时，new.target会返回子类。


2. Module
- `import,export default`:(img)[http://es6.ruanyifeng.com/#docs/module#export-default命令]
- `import、export正确及错误使用方法`:(img)

3. Enhanced Object Literals

4. Template Strings
- (es6中引入的**模板字符串**:[http://es6.ruanyifeng.com/#docs/string#模板字符串])
- 模板字符串中要引入变量,变量需写在`${}`中.

5. Destructuring
	- airbnb eg->(img)

6. Default + Rest + Spread(默认参数+不定参数+参数展开)
- eg->(img)

7. Let + Const
- `let` 是新的 `var`,只在块级作用域内有效
- `const`是单赋值,声明的是块级作用域的常量。
- 具有静态限制,必须先声明后使用.

8. Iterators + For..Of
-

9. Generator函数
- `function`和`()`之间要有`*`间隔的函数,它是一个状态机,内部封装了多个状态;还是一个遍历器对象生成函数,返回遍历对象.
- 执行后,会产生一个指针,通过`.next()`进行单步执行(eg->(img))
	- yeild语句:
		- yeild不能用在普通函数里
		- 其它注意:(img)
	2. next方法的参数
	- `next()`的参数会被当做上一个`yeild`语句的返回值.
	3. for…of循环
10. 装饰器
- Decorator是一个*函数*,用来改变class的行为.

常用语法:
1. 函数默认值: eg->(img)
2. 更新并创建一个新对象:eg->(img)
