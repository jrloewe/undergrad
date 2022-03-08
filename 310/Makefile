CC=gcc
CFLAGS=-g -Wall -Wstrict-prototypes -std=gnu99
LFLAGS=-lm

all:		generate-data	print-data

generate-data:	generate-data.c
		$(CC) $(CFLAGS) -o generate-data generate-data.c

print-data:	print-data.c
		$(CC) $(CFLAGS) -o print-data print-data.c

clean:
		rm -f *.o core* generate-data print-data
