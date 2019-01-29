//implementation for sum_series task
//190129, softbobo

#include<stdio.h>

int main() {
    int x = 1;
    int sum = 0;
    while(x != 0) {
        scanf("%d", &x);
        sum += x; }
    printf("%d\n", sum);
    return 0; }