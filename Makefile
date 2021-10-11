CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:					test1.test test2.test test3.test test4.test test5.test

%.o:					%.c %.h
							gcc $(CFLAGS) -c $<

test1.test: 	queue.o test1.o
							gcc $(CFLAGS) $^ -o $@

test2.test:		queue.o test2.o
							gcc $(CFLAGS) queue.o test2.o -o $@

test3.test:		queue.o test3.o
							gcc $(CFLAGS) queue.o test3.o -o $@

test4.test:		queue.o test4.o
							gcc $(CFLAGS) queue.o test4.o -o $@

test5.test:   queue.o test5.o
							gcc $(CFLAGS) queue.o test5.o -o $@

clean.test:
							rm -f *.o *.test
