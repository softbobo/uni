/*
header file for the whole lab task block number three

Softbobo
03 May 2019
*/


#include<iostream>

/* this one was given, didn't think of the name myself */
struct lelem {
    int data = 0;
    lelem* next = NULL;
};


/* function declarations */
void ll_print(lelem* head);                                //3.1
unsigned ll_size(lelem* head);                             //3.2
int ll_sum(lelem* head, int max);                          //3.3
float ll_negrelation(lelem* head);                         //3.4
void ll_insert_front(lelem* &head, int val);               //3.5
void ll_insert_back(lelem* &head, int data);               //3.6
void ll_remove_front(lelem*& head);                        //3.7

void ll_remove(lelem* &head);                              //3.9






void ll_print_recursive(lelem* &head);                     //3.16


