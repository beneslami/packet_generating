CC = gcc
CFLAGS  = -Wall
DEPS = headers.h
EXTERN = -pthread

all: main.o arp.o
	$(CC) -o main main.o arp.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

arp.o: arp.c
	$(CC) $(CFLAGS) -c arp.c

clean:
	rm -f *.o *.ko *.out
