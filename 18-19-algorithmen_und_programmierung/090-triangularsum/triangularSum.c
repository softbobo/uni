//implementation of task 090 - specified in pdf
//softbobo 190117

#include <stdlib.h>
#include <stdio.h>
unsigned ts(unsigned n);

int main(int argc, char** argv) {
    if(argc != 2) return -1;
    unsigned num_in = strtoull(argv[1], NULL, 10);
    printf("ts(%d)=%d", num_in, ts(num_in));
    return 0; }

unsigned ts(unsigned n) {
    unsigned tri_sum = 0;
    for(unsigned i = 1; i <= n; i++) {
        tri_sum += i; }
    return tri_sum;}