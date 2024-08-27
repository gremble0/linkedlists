CC=clang
CFLAGS=-Wall -Wextra
OBJS=sll.o

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) main.c -o main

sll.o:
	$(CC) $(CFLAGS) -c sll.c -o sll.o

clean:
	rm -f *.o
	rm -f *.a
	rm -f test
