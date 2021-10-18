CFLAGS=-Wall -pedantic -std=c11 -I../src -g

all:					test1.test test2.test test3.test test4.test test5.test test6.test

test1.test: 	../src/queue.o ../test/test1.o
							gcc $(CFLAGS) ../src/queue.o ../test/test1.o -o $@

test2.test:		../src/queue.o ../test/test2.o
							gcc $(CFLAGS) ../src/queue.o ../test/test2.o -o $@

test3.test:		../src/queue.o ../test/test3.o
							gcc $(CFLAGS) ../src/queue.o ../test/test3.o -o $@

test4.test:		../src/queue.o ../test/test4.o
							gcc $(CFLAGS) ../src/queue.o ../test/test4.o -o $@

test5.test:   ../src/queue.o ../test/test5.o
							gcc $(CFLAGS) ../src/queue.o ../test/test5.o -o $@

test6.test:   ../src/queue.o ../test/test6.o
							gcc $(CFLAGS) $^ -o $@

clean:
							rm -f *.test *~
