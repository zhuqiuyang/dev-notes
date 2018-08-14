// A Lua module written in C

#include "lua.h"

#include <stdio.h>

int luaopen_time(lua_State *L) {
  // Set up the module
  printf("Hi From %s\n", __FUNCTION__);
  return 0;
}