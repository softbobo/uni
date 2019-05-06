/*
task: write a function that that removes the first entry holding the specified value

softbobo 06 May 2019
*/

using namespace std;

#include"3.h"

bool ll_remove_data(lelem* head, int val) {
    lelem* previous = head;

    while(head->next != NULL) {
        if(head->data == val) {
            previous = head->next;
            ll_remove_front(head);
            return true;
        }
    }

    return false;
}