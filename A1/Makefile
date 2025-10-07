CC = clang
CFLAGS = -std=c99 -Wall -pedantic -fPIC -I./src

all: bin/test0 lib/libarray.so lib/liblist.so lib/libmem.so

bin/test0: obj/test0.o lib/libarray.so lib/liblist.so lib/libmem.so
	$(CC) $(CFLAGS) obj/test0.o -o bin/test0 -Llib -larray -llist -lmem

lib/libarray.so: obj/array.o
	$(CC) -fPIC -shared obj/array.o -o lib/libarray.so

lib/liblist.so: obj/list.o
	$(CC) -fPIC -shared obj/list.o -o lib/liblist.so

lib/libmem.so: obj/mem.o
	$(CC) -fPIC -shared obj/mem.o -o lib/libmem.so

obj/test0.o: src/test0.c
	$(CC) $(CFLAGS) -c src/test0.c -o obj/test0.o

obj/array.o: src/array.c src/array.h
	$(CC) $(CFLAGS) -c src/array.c -o obj/array.o

obj/list.o: src/list.c src/list.h
	$(CC) $(CFLAGS) -c src/list.c -o obj/list.o

obj/mem.o: src/mem.c src/mem.h
	$(CC) $(CFLAGS) -c src/mem.c -o obj/mem.o

clean:
	rm -f obj/*.o

cleaner:
	rm -f obj/*.o lib/*.so bin/test0