### 2. Module
- export 作为形参传入, 直接赋值形参会改变形参的引用. 所以使用`module.exports`.
- `dlopen()`来调用`.node`文件.
- js 核心module编译成 C++ 字符串.(而非直接可执行.)
- `build-in` module, pure C write, eg: `crypto, evals, buffer, os`