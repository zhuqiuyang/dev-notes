// demo.c
//
// A skeleton Lua module written in C.
//

#include "printstack.h"

#include "lua.h"
#include "lauxlib.h"


int f(lua_State *L) {
      // stack = [<args>]
  print_stack(L);
  return 0;
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