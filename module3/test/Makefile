CFLAGS=-Wall -pedantic -std=c11 -I../src -g

all:					test1.o test2.o test3.o test4.o test5.o test6.o htest1.o htest2.o htest3.o 

%.o:					%.c 
							gcc $(CFLAGS) -c $<

clean:
							rm -f *.o 
