//simple test frame for basedNumbers
#include"basedNumbers.h"
#include<stdio.h>

int main() {
    basedNumber num_1 = {2, "1101"};            //13
    basedNumber num_2 = {5, "123"};             //38
    basedNumber num_3 = {16, "1d5A"};           //7514
    basedNumber *test_1 = malloc(3 * sizeof(basedNumber));
    test_1[0] = num_1;
    test_1[1] = num_2;
    test_1[2] = num_3;
    printf("sum of test 1 is %i\n", sumOfBasedNumbers(test_1, 3));
    free(test_1);
    return 0;
}