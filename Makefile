CFLAGS: -Wall --pedantic -std=c11 -I

%.o: %.c %.h
		 gcc $(CFLAGS) -c $<
