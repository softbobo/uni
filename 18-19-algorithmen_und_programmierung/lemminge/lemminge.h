//header file for the lemminge task, for func declarations

//#include<stdlib.h>
#include<stdio.h>

typedef struct pole {
//all the poles represented in a singly linked list;
    unsigned pos;                   //height of every horizontal pole
    unsigned left;                  //left end
    unsigned right;                 //right end
    struct pole *next = NULL;       //next list entry              
};

typedef struct board {
    /* this is the overarching datastructure, has the total number of lemmings and a pointer
    to the first list entry */
    unsigned le_ming;               //tot number of horizontal poles/lemmings, first number of input
    struct pole *first;
};

struct board* input(void);