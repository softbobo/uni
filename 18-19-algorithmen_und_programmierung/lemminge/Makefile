#Makefile for lemminge

CFLAGS= -g -Wall -Wextra -pedantic
CC= c99
OBJECTS= main.o

lemminge: ${OBJECTS}
	gcc ${CFLAGS} ${CC} -o lemminge
main.o: main.c
	gcc ${CFLAGS} ${CC} -c main.o