// demo.c
//
// A skeleton Lua module written in C.
//

#include "printstack.h"

#include "lauxlib.h"
#include "lua.h"

int f(lua_State *L) {
  // stack = [<args>]
  lua_pushnumber(L, 12.3);
  // stack = [<args>, 12.3]
  lua_pushstring(L, "Hi");
  // stack = [<args>, 12.3, "Hi"]
  lua_pushnil(L);
  // stack = [<args>, 12.3, "Hi", nil]
  lua_pushboolean(L, 1);
  // stack = [<args>, 12.3, "Hi", nil, true]
  print_stack(L);
  return 1;
  // stack = [<args>, 数字代表 LAST 可见数]
}

int g(lua_State *L) {
  // stack = [<args>]
  print_stack(L);
  return 0;
}

#define setup_global_fn(fn_name) \
  lua_pushcfunction(L, fn_name); \
  lua_setglobal(L, #fn_name);

int luaopen_demo(lua_State *L) {
  setup_global_fn(f);
  setup_global_fn(g);
  return 0;
}