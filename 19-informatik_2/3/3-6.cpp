/*
task: write a function, that inserts new entries at the list's back

softbobo 06 May 2019
*/

using namespace std;

#include"3.h"

/* so this is a pretty dumb way to insert somethin at the back of the list,
i know. but i am too lazy atm to implement a tail pointer - maybe later */
void ll_insert_back(lelem* &head, int data) {
    while(head->next != NULL) {
        head = head->next;
    }

    lelem* temp = new lelem;
    temp->data = data;
    head->next = temp;
}