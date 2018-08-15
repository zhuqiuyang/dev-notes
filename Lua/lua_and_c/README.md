### lua and c

> 2018-08-14-Tues

```sh
curl -R -O http://www.lua.org/ftp/lua-5.3.5.tar.gz
tar zxf lua-5.3.5.tar.gz

cd lua-5.3.5

make macosx test
```

### 1st example: lua called time.c

> https://www.youtube.com/watch?v=UiZ051A22h8
>
> http://lua-users.org/wiki/BuildingModules

```sh
alias lua="$PWD/lua-5.3.5/src/lua"

gcc -bundle -undefined dynamic_lookup -o time.so time.c
# 编译出了 time.so
lua
time = require 'time'
```

```sh
# name of .so
nm -g time.so

# which lib it depends on
otool -L time.so

# input in lua REPL
= package.path
# which include ./?.so
= package.cpath
```

#### 增加了 get_time

- `lua_` prefix in lua core library(`lua.h`)
- `luaL_`prefix: 易于区分, small & build on the top of core api(`lauxlib.h`)

> `return 0` 改成了`return 1`, 即可以返回.

#### Make a module universally avaiable

- `= package.cpath`, and `copy *.so` to `/usr/local/lua/lib/5.3/`
- `Makefile`: 要用`tab`做分隔符.

### Chapter 24. An Overview of the C API

> https://www.lua.org/pil/24.2.html#API-stack

lua `settable` 的 C 版 `void lua_settable (lua_Value a, lua_Value k, lua_Value v);`, 没有这样设计的原因:

- Lua 定义出的接口, 应普适各种语言, C/Cpp/Java...
- 变量置于 C 中, Lua 无法进行 GC.

所以, Lua 和 C 的交互通过`Stack`(LIFO)传递:

#### 24.2 Pushing Elements

不同类型, 入栈, 调用不同的 `C` fn:

- `void lua_pushnil (lua_State \*L);`
- `void lua_pushboolean (lua_State \*L, int bool);`

### Lua C API tutorial: using the stack and working with tables

> https://www.youtube.com/watch?v=5uhHkeVpcgo

#### write values

- all c fn called by lua, signature 一致
  - input: `lus_State` ptr
  - output: `int`(`zero`return value 对 lua 可见.)

```c
int f(lua_State *L) {
  print_stack(L);
  return 0;
}
```

```sh
require 'demo'
f()
f(1,2,3)
f(1, {}, 'hola')

make; lua -i -e "require 'demo'"
```

#### stack ctrl

#### reading values

#### using tables
