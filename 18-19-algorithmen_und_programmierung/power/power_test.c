//test main() for power.c
//softbobo 190116

#include<stdio.h>

int main() {
    int val = 7;
    int exp = 4;

    printf("power(%d): %d \n", val, power(val, exp));
    printf("poly1(%d): %d \n", val, poly1(val, exp));
    printf("polyAlter(%d): %d \n", val, polyAlter(val, exp));
    return 0;
}