//test main() for the grep.c task
//softbobo 20190130

#include<string.h>
#include<stdio.h>
#include"grp.h"

int main(int argc, char** argv) {
    int* result = grep(argv[2], argv[1]);
    int end = strlen(result);
    for(int i = 0; i <= end; i++) {
        printf("%d ", result[i]);
    } 

    free(result);
    return 0;
}