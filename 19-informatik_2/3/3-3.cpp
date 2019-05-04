/* 
task 3.3: write function, that sums up all list entries 

softbobo 03 May 2019
*/ 

using namespace std;

#include"3.h"

int ll_sum(lelem* head, int max) {
    int sum = 0;
    
    for(int i = 0; i < max; i++) {
        sum += head->data;
    }

    return sum;
}