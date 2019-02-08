//header file for the lemminge task, for func declarations

#include<stdio.h>

/* to do:
- initialize next-pointer to NULL (throws error?) */

typedef struct {
//all the poles represented in a singly linked list;
    unsigned pos;                   //height of every horizontal pole
    unsigned left;                  //left end
    unsigned right;                 //right end
    struct pole* next;              //next list entry              
} pole;

typedef struct{
    /* this is the overarching datastructure, has the total number of lemmings and a pointer
    to the first list entry */
    unsigned le_ming;               //tot number of vertical poles/lemmings, first number of input
    struct pole* head;
} board;

