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

#include<iostream>

/* function declarations */
void ll_print(lelem* head);                                //3.1
unsigned ll_size(lelem* head);                             //3.2
int ll_sum(lelem* head, int max);                          //3.3

void ll_insert_front(lelem* &head, int val);               //3.5

void ll_remove_front(lelem*& head);                        //3.7

void ll_remove(lelem* &head);                               //3.9


