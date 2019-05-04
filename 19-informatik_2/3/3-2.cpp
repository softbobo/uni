/*
task: write a function that gives back the number of elementsof the list

softbobo 04 May 2019
*/

using namespace std;

#include"3.h"

unsigned ll_size(lelem* head) {
    unsigned count = 0;

    while(head != NULL) {
        count++;
        head = head->next; 
    }

    return count;
}