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

> OSX 下实战视频: https://www.youtube.com/watch?v=5uhHkeVpcgo
>
> Lua C API tutorial: using the stack and working with tables

视频补充:`all c fn called by lua, signature 一致`

- input: `lus_State` ptr
- output: `int`(返回栈顶 LAST int 个元素)

```c
int f(lua_State *L) {
  print_stack(L);
  return 0; // 函数无返回, 1表示返回栈顶元素
}

void lua_pushnil (lua_State *L);
void lua_pushboolean (lua_State *L, int bool);
void lua_pushnumber (lua_State *L, double n);
void lua_pushlstring (lua_State *L, const char *s, size_t length);
void lua_pushstring (lua_State *L, const char *s);
```

```sh
make; lua -i -e "require 'demo'"

f()
f(1,2,3)
f(1, {}, 'hola')
a = f()
= a
```

#### stack ctrl

> https://www.lua.org/pil/24.2.3.html

- lua index 从 `1`开始

```c
int   lua_checkstack (lua_State *L, int sz);
int   lua_gettop (lua_State *L);
void  lua_settop (lua_State *L, int index);

#define lua_pop(L,n)  lua_settop(L, -(n)-1)

void  lua_pushvalue (lua_State *L, int index);
void  lua_remove (lua_State *L, int index);
void  lua_insert (lua_State *L, int index);
void  lua_replace (lua_State *L, int index);
```

- `lua_checkstack`: stack 空间是否能满足需要
- `lua_gettop`: 返回栈顶元素的 `index` (即栈长度)
- `lua_settop`: 从底部保留; `settop(L, -x), 代表保留到`倒数第 x`个元素, 即(n - x + 1)`
- `lua_pop`: 即从顶部删除;
- `lua_pushvalue`: 顶部插入一个元素, 内容 copy 自指定 `index` 的元素
- `lua_remove`: 删除指定`index`的元素, 其后元素`shift down`
- `lua_insert`: moves the top element into the given position, 其余元素`shift up`到空位(右移).
- `lua_replace`: pops 栈顶元素, 然后`set`到指定 `index`, without moving anything.

补充:

> https://github.com/tylerneylon/lua_api_demo/blob/master/readme.md#using-the-module

```sh
luarocks install apidemo
# 可以在lua 内模拟 lua C API
```

#### 24.2.2 querying element

- `negative indices`: `-1`代表栈顶元素, `-2`代表倒数第二个.

##### check type

> check 指定的 index 的元素, 是否是对应 type.

```c
int lua_is... (lua_State *L, int index);
```

`lua_type`:

##### 返回指定类型

```c
int            lua_toboolean (lua_State *L, int index);
double         lua_tonumber (lua_State *L, int index);
const char    *lua_tostring (lua_State *L, int index);
size_t         lua_strlen (lua_State *L, int index);
```

#### using tables
