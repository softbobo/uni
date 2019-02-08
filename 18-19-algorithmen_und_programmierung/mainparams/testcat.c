//implementation of mainparams task, specified in pdf
//190130 softbobo

#include<stdio.h>

char* catArg(int argc, char** argv);

int main(int argc, char** argv) {
    if(argc < 2) return -1;
    catArg(argc, **argv);
    return 0;
}