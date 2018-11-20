//AuP 4th task winter semester 2018/19, written by softbobo
//find task in README.md

/* tasks:
-configure debugger 
-write func(), that accumulates all input into single string
and discards all spaces and other unwanted signs
-add printf in main() that shows, if new string is correct
-adjust argc to ull (possible?)*/

#include "stdaup.h"

char* single_str(char **str_old, char* str_new, int max, int start);

int main(int argc, char **argv){

    /*main() function takes arguments, calls functions to do 'sub-algorithms'
    and outputs result*/

    if(argc<0) return -1;               //check, if sufficient number of args are given
    
    long long i;
    for(i=0; i<=argc; i++){
        //debug-statement: all args handed over? delete before handing in
        printf(" args count: %d, input: \"%s\"\n", argc, argv[i]);                                 
    }
    
    char* str = malloc(sizeof(argv));
    char* single = single_str(argv, str, argc, 0); 
    printf("new single string: \"%str\"\n", single);
        //debug-statement: all args in one single string now?

    free(single_str);


    return 0;
}

char* single_str(char **str_old, char* str_new, int max, int j){
    /*single_str takes all input-strings and puts them into one long single array
    and gives that back to main()*/

    int h;
    for(h = 1; h<=max; h++){
        char* temp_arr = str_old[h];
        int i;
        for(i = 1; i<=max; i++){
            switch(temp_arr[i]){
                case '0':
                case '1':                               //intentional fallthrough here
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '.':
                case ',':
                case '+':
                case '-': temp_arr[i] = str_new[j];     //return-string only gets populated with 'wanted' chars
                    break;
                case '/0': return str_new;              //exit when array reaches end
                    break;
                default: j=j;                           /*default case to 'do nothing' when the index reaches some
                                                        'unwanted' char. really necessary? implemented correctly?*/
            }
        }
    }
}   

