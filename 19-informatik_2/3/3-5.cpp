/*
task 3.5: write a method to add a new list item at the lists head
and explain why head is passed by reference

softbobo 03 May 2019
*/

/*
since we are adding to the list's front, it's easier to pass the head pointer 
by reference. this way we don't need to return a new pointer pointing to the
new location which is now the beginning of the list. instead, we get the 
original pointer and redirect it.
also, technically, we have to operations less per call of the function since
1. the value of head doesn't have to be copied to the stack of the function call
2. head doesn't need to be updated with the return value of the function
*/

using namespace std;

#include"3.h"

void ll_insert_front(lelem* &head, int val) {
    lelem* temp = new lelem;
    temp->data = val;
    temp->next = head;
    head = temp; 
}