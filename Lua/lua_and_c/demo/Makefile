all: demo.so

clean:
	rm *.o *.so

demo.so: demo.o printstack.o
	cc -bundle -undefined dynamic_lookup -o demo.so demo.o printstack.o

demo.o: demo.c
	cc -fPIC -o $@ -c $< -I../lua_src

printstack.o: printstack.c
	cc -fPIC -o $@ -c $< -I../lua_src
