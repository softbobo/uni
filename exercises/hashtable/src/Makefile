CFLAGS= -g -Wall -Wextra -pedantic
OBJS= hashtable.o main.o prime.o

all: $(OBJS)
	gcc $(CFLAGS) $(OBJS) -lm -o hashtable

hashtable.o: 
	gcc $(CFLAGS) -c  hashtable.c

prime.o: 
	gcc $(CFLAGS) -c  prime.c

main.o: 
	gcc $(CFLAGS) -c main.c