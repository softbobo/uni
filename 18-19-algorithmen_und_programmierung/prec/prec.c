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

char* single_str(char **str_old, char* str_new, int max){
    /*single_str takes all input-strings and puts them into one long single array
    and gives that back to main()*/

    int h;
    for(h = 1; h<=max; h++){
        char* temp_arr_1 = str_old[h];                      //populate temp_arr_1 with the single string of **argv
        char* temp_arr_2 = sizeof(temp_arr_1);              //while temp_arr_1 is the 'uncleaned' string, temp_arr_2 is its 'cleaned' version
        int i, j;
        for(i = 0; temp_arr_1[i] != '/0'; i++){             //parse through temp_arr
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
                    case '-': {
                        temp_arr_2[j] = temp_arr_2[j];
                        j++;}                                   //return-string only gets populated with 'wanted' chars
                        break;
                    default: j=j;                           /*default case to 'do nothing' when the index reaches some
                                                            'unwanted' char. really necessary? implemented correctly?*/
               }
            return temp_arr_2;                              
            }
        str_new += temp_arr_2;                              //cleaned versions of single strings get added to one big long string
        }
    return str_new;
}


