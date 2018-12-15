//test-file for functions in charset.c, not to be included later

#include<stdio.h>
#include"charset.h"
#include"stdaup.h"


int main()
{
    //tests for func charset_new

    //const char str_11[] = "ABCabc";
    //const char str_12[] = "fg hj 1236 lm";
    //const char str_13[] = "AAAAAA bbbb 678 888 ß §";

    //struct charset *temp_str;
    //temp_str = malloc(sizeof(struct charset));
    //temp_str = charset_new(str_11);
    //printf("Function charset_new, String 1: %s \n", temp_str->bits);
    //printf("Function charset_new String 2: %s \n", charset_new(str_2));
    //printf("Function charset_new String 3: %s \n", charset_new(str_3));
//
    ////tests for charset op
//
    //charset_t* str_21;
    //str_21.bits -> {1};
    //charset_t* str_22;
    //str_22.bits -> {1};
    ////charset_t* str_23;
    ////str_23.bits -> {NULL};
//
    //int result_2a = charset_op(str_21, str_22, CS_UNION);
    //int result_2b = charset_op(str_21, str_22, CS_CUT);
    //int result_2c = charset_op(str_21, str_22, CS_SYMDIFF);
//
    //printf("success union: %d, success cut: %d, success symdiff: %d\n", result_2a, result_2b, result_2c);

    //tests for charset_tos
    charset_t* str_31 = "AdBCe";

    printf("string ordered: %s\n", charset_tos(str_31));

    return 0;
}