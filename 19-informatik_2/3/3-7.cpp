/*
write a function, that removes the first element of the list

softbobo 03 May 2019
*/

using namespace std;

#include"3.h"

void ll_remove_front(lelem* &head) {
    if(head == NULL) {
        cout << "list is empty" << endl;
        return;
    }

    lelem* temp = head->next;
    head->next = temp->next;
    delete temp;
}