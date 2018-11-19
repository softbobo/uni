//AuP 4th task winter semester 2018/19, written by softbobo
//find task in README.md

/* tasks:
-configure debugger 
*/

#include "stdaup.h"

int main(int argc, char **argv){

    /*main() function takes arguments, calls functions to do 'sub-algorithms'
    and outputs result*/

    if(argc<0) return -1;               //check, if sufficient number of args are given
    
    long long i;
    for(i=0; i<=argc; i++){
        //debug-statement: all args handed over?
        printf(" args count: %d, input: \"%s\"\n", argc, argv[i]);                                 
    }
    

    return 0;
}