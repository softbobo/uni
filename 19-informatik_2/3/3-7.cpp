/*
write a function, that removes the first element of the list

softbobo 03 May 2019
*/

using namespace std;

#include"3.h"
#include<iostream>

void ll_remove_front(lelem* &head, unsigned len) {
    if(len == 0) {
        cout << "list is empty" << endl;
        return;
    }

    lelem* temp = head->next;
    delete head;
    head = temp;
}