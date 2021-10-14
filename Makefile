CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:					htest1.test htest2.test #htest3.test

%.o:					%.c %.h
							gcc $(CFLAGS) -c $<

htest1.test: 	hashfile.o queue.o htest1.o
							gcc $(CFLAGS) $^ -o $@

htest2.test:	hashfile.o queue.o htest2.o
							gcc $(CFLAGS) queue.o test2.o -o $@

#htest3.test:	hashfile.o htest3.o
#							gcc $(CFLAGS) queue.o test3.o -o $@

clean:
							rm -f *.o *.test #\'*\'
