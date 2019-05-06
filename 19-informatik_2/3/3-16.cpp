/*
task: write a recursive function, that puts out all list elements

softbobo 06 May 2019
*/

using namespace std;

#include"3.h"

void ll_print_recursive(lelem* &head) {
    if(head != NULL) {
        cout << head->data << " ";
        return ll_print_recursive(head->next);
    }
}