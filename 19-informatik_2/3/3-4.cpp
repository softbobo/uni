/*
task: write a function that calculates the relation of negative
elements in the list and gives back a a float < 1.0 representing the 
actual percentage (via variable * 100 = percentage)

softbobo 04 May 2019
*/

using namespace std;

#include"3.h"

float ll_negrelation(lelem* head) {
    float negs = 0.0;
    float total = float(ll_size(head));

    while(head != NULL) {
        if(head->data < 0) { negs += 1.0; }
        head = head->next;
    }

    return (total/negs);
}

