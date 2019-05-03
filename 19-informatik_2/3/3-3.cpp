/* 
task 3.3: write function, that sums up all list entries 

softbobo 03 May 2019
*/ 

#include"3.h"
#include<iostream>

int ll_sum(lelem* head) {
    int sum = 0;
    
    for(;;head++) {
        sum += head->data;
    }

    return sum;
}