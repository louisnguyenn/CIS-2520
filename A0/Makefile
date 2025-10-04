CC = clang
CFLAGS = -std=c99 -Wall -pedantic -fPIC -I./src

all: bin/a0 lib/libutil.so 

bin/a0: obj/main.o lib/libutil.so
	$(CC) $(CFLAGS) obj/main.o -o bin/a0 -Llib -lutil

lib/libutil.so: obj/util.o
	$(CC) -fPIC -shared obj/util.o -o lib/libutil.so

obj/main.o: src/main.c src/util.h
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o

obj/util.o: src/util.c src/util.h
	$(CC) $(CFLAGS) -c src/util.c -o obj/util.o

clean:
	rm obj/*.o

cleaner:
	rm obj/*.o lib/*.so bin/a0