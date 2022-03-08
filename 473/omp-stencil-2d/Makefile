CC=gcc
CFLAGS=-g -Wall -Wstrict-prototypes -std=gnu99 -fopenmp
LFLAGS=-lm -fopenmp

all:	print-2d make-2d stencil-2d stencil-2d-stack omp-stencil-2d omp-stencil-2d-stack

driver:									utilities.o driver.o
	$(CC) $(LFLAGS) -o driver utilities.o driver.o
print-2d:								utilities.o print-2d.o
	$(CC) $(LFLAGS) -o print-2d utilities.o print-2d.o
make-2d:								utilities.o make-2d.o
	$(CC) $(LFLAGS) -o make-2d utilities.o make-2d.o
stencil-2d:							utilities.o stencil-2d.o
	$(CC) $(LFLAGS) -o stencil-2d utilities.o stencil-2d.o
stencil-2d-stack: 			utilities.o stencil-2d-stack.o
	$(CC) $(LFLAGS) -o stencil-2d-stack utilities.o stencil-2d-stack.o
omp-stencil-2d:					utilities.o omp-stencil-2d.o
	$(CC) $(LFLAGS) -o omp-stencil-2d utilities.o omp-stencil-2d.o
omp-stencil-2d-stack:		utilities.o omp-stencil-2d-stack.o
	$(CC) $(LFLAGS) -o omp-stencil-2d-stack utilities.o omp-stencil-2d-stack.o

utilities.o: 						utilities.c utilities.h
	$(CC) $(CFLAGS) -c utilities.c
driver.o: 							driver.c utilities.h
	$(CC) $(CFLAGS) -c driver.c
print-2d.o: 						print-2d.c utilities.h
	$(CC) $(CFLAGS) -c print-2d.c
make-2d.o: 							make-2d.c utilities.h
	$(CC) $(CFLAGS) -c make-2d.c
stencil-2d.o: 					stencil-2d.c utilities.h
	$(CC) $(CFLAGS) -c stencil-2d.c
stencil-2d-stack.o:			stencil-2d-stack.c utilities.h
	$(CC) $(CFLAGS) -c stencil-2d-stack.c
omp-stencil-2d.o:				omp-stencil-2d.c utilities.h
	$(CC) $(CFLAGS) -c omp-stencil-2d.c
omp-stencil-2d-stack.o:	omp-stencil-2d-stack.c utilities.h
	$(CC) $(CLFAGS) -c omp-stencil-2d-stack.c

clean:
	rm -f *.o *.dat *.raw core* print-2d make-2d stencil-2d stencil-2d-stack omp-stencil-2d omp-stencil-2d-stack
