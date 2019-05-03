/*
header file for the whole lab task block number three

Softbobo
03 May 2019
*/

/* this one was given, didn't think of the name myself */
struct lelem {
    int data;
    lelem* next;
};

/* function declarations */
void ll_print(lelem* head);                             //3.1



void insert_front(lelem* &head, int val);               //3.5