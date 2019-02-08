//implementation of mainparams task, specified in pdf
//190130 softbobo

#include<stdio.h>

char* catArg(int argc, char** argv) {
    for(int i = 1; i <= argc; i ++) {
        printf("\"");
        for(int j = 0; argv[i][j] != '\0'; j++)
            printf("%c", argv[i][j]);
        printf("\"");
    }
    return "";
}