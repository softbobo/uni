//main to test triangularSum.c
//softbobo 190117

#include <stdlib.h>
#include <stdio.h>
unsigned ts(unsigned n);

int main(int argc, char** argv) {
    if(argc != 2) return -1;
    unsigned num_in = strtoull(argv[1], NULL, 10);
    printf("triangular sum of %s is %d\n", argv[1], ts(num_in));
    return 0;
}