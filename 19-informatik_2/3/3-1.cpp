/* 
first task in block three, implement function that prints linked list

softbobo 03 may 2019
 */

using namespace std;

#include<iostream>
#include"3.h"

void ll_print(lelem* head) {
    if(head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    while(head != NULL) { 
        cout << head->data << endl;
        head = head->next;
        }
}