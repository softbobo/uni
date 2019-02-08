//implementation for happynumber, task defined in pdf
//softbobo 190129

/* to do: 
- parse both halves of string to numbers
- iterate over both nums, calculate checksum
- compare checksums, return answer
*/

#include<string.h>
#include<stdio.h>
int main(int argc, char** argv) {
    if(argc != 2) return -1;
    if(strlen(argv[1]) != 6) {
        printf("nein");
        return 0; }
    int check_first = 0;
    int check_second = 0;    
    for(int i = 0; i < 3; i++) {
        check_first += (int)argv[1][i] - 48; }
    for(int i = 3; i < 6; i++) {
        check_second += (int)argv[1][i] - 48; }
    if(check_first == check_second) {
        printf("ja"); }
    else {
        printf("nein"); }
    return 0;
}