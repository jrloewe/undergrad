CC=gcc
CFLAGS=-g -Wall -Wstrict-prototypes -std=gnu99
LFLAGS=-lm
all:	print-2d make-2d stencil-2d
driver:	utilities.o driver.o
	$(CC) $(LFLAGS) -o driver utilities.o driver.o
print-2d:	utilities.o print-2d.o
	$(CC) $(LFLAGS) -o print-2d utilities.o print-2d.o
make-2d:	utilities.o make-2d.o
	$(CC) $(LFLAGS) -o make-2d utilities.o make-2d.o
stencil-2d:	utilities.o stencil-2d.o
	$(CC) $(LFLAGS) -o stencil-2d utilities.o stencil-2d.o
utilities.o: utilities.c utilities.h
	$(CC) $(CFLAGS) -c utilities.c
driver.o: driver.c utilities.h
	$(CC) $(CFLAGS) -c driver.c
print-2d.o: print-2d.c utilities.h
	$(CC) $(CFLAGS) -c print-2d.c
make-2d.o: make-2d.c utilities.h
	$(CC) $(CFLAGS) -c make-2d.c
stencil-2d.o: stencil-2d.c utilities.h
	$(CC) $(CFLAGS) -c stencil-2d.c
clean:
	rm -f *.o core* *.dat *.raw print-2d make-2d stencil-2d
