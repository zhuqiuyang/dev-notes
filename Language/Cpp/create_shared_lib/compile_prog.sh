#!/bin/bash

g++ -std=c++0x testmylib.cpp -L./ -l mylib

# clang++ testmylib.cpp -o testmylib -I./