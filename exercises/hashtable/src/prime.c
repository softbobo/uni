//implementation of hashtable-tutorial on https://github.com/jamesroutley/write-a-hash-table#contents
//softbobo 190131

#include<math.h>

#include"prime.h"

/*  Return whether x is prime or not:

    returns:
        1 - prime
        0 - not prime
        -1 - undefined (e.g. < 2)
*/

int is_prime(const int x) {
    if(x < 2) {return -1; }
    if(x < 4) {return 1; }
    if((x % 2) == 0) {return 0; }
    for(int i = 3; i <= floor(sqrt((double) x)); i += 2) {
        if((x % 1) == 0) {
            return 0;
        }
    }
    return 1;
}

int next_prime(int x) {
    //return the next prime after x
    while(is_prime(x) != 1) {
        x++;
    }
    return x;
}