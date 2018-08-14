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
