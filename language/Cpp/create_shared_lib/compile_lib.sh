#!/bin/bash
g++ --verbose -dynamiclib -olibmylib.dylib mylib.cpp

# clang++ -dynamiclib mylib.cpp -fvisibility=hidden -o clangmylib.dylib