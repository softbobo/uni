//implementation of task 090 - specified in pdf
//softbobo 190117

/* for defensive programming:
-change data types to what is specified in wchar.h
-make check for NULL and greater than ulongmax in input
*/

#include<stdio.h>

unsigned ts(unsigned n) {
    unsigned tri_sum = 0;
    for(unsigned i = 1; i <= n; i++) {
        tri_sum += i; }
    printf("ts(%d) = %d", n, tri_sum);
    return tri_sum;
}