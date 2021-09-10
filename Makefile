all: first

first: main.c
	gcc main.c -o first -llua -L/Users/jefferson/.luaver/lua/5.4.3/lib -I/Users/jefferson/.luaver/lua/5.4.3/include

clean:
	rm -rf *.o *~ first