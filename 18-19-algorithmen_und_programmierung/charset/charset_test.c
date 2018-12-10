//test-file for functions in charset.c, not to be included later

#include<stdio.h>
#include"charset.h"
#include"stdaup.h"


int main()
{
    const char str_1[] = "ABCabc";
    const char str_2[] = "fg hj 1236 lm";
    const char str_3[] = "AAAAAA bbbb 678 888 ß §";

    //tests for func charset_new
    printf("Function charset_new String 1: %s \n", charset_new(str_1));
    printf("Function charset_new String 2: %s \n", charset_new(str_2));
    printf("Function charset_new String 3: %s \n", charset_new(str_3));

    return 0;
}