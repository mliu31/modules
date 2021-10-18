CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:					queue.o hash.o 

%.o:					%.c %.h
							gcc $(CFLAGS) -c $<

clean:
							rm -f *.o 
