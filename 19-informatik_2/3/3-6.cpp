/*
task: write a function, that inserts new entries at the list's back

softbobo 06 May 2019
*/

using namespace std;

#include"3.h"

void ll_insert_back(lelem* &head, int data) {
    lelem* tail = head;
    
    while(tail->next != NULL) {
        tail = tail->next;
    }

    lelem* temp = new lelem;
    temp->data = data;
    tail->next = temp;
}