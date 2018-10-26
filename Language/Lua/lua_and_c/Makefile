# Makefile
#
# This file is written for use on Mac OS X.
#

all: time.so

clean:
	rm *.so

time.so: time.c
	cc -bundle -undefined dynamic_lookup -o time.so time.c -Ilua_src
