CC=clang
CFLAGS=-Wall -Wextra -g
OBJS=sll.o

all: clean $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) main.c -o main

sll.o:
	$(CC) $(CFLAGS) -c sll.c -o sll.o

clean:
	rm -f *.o
	rm -f main
