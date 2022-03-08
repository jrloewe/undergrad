CC=gcc
CFLAGS=-g -Wall -Wstrict-prototypes -std=gnu99
LFLAGS=-lm

all:					pi_serial	pi_parallel
pi_serial:		pi_serial.c
	$(CC) $(CFLAGS) -o pi_serial pi_serial.c $(LFLAGS)
pi_parallel:	pi_parallel.c
	$(CC) $(CFLAGS) -o pi_parallel pi_parallel.c $(LFLAGS) -fopenmp
clean:
	rm -f *.o core* pi_serial pi_parallel
