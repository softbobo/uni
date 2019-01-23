//implementation of task basedNumbers as specified in the pdf
//softbobo 190122

/*this file should implement a function that takes an arbitrary count of numbers
to a certain base (between 1 and 36), stores these in a struct (specified in 
basedNumbers.h), parses those to the decimal base and returns the sum of all numbers 
added.
bugs: 
- segfault when algo encounters a char
- calculation doesnt take val of number but ascii val
to do:
- write error checks for null pointers (anything else) in sumOfBasedNumbers
- implement test-main program (not sure if this is to be incorporated)
- write dedicated function to parse from arbitrary base to decimal
algorithm: 
- compute strlen of number 
- reverse iterate over array, increment sum by respective power 
*/

#include"basedNumbers.h"
#include<math.h>
#include<string.h>

unsigned base_convert(basedNumber num);

unsigned int sumOfBasedNumbers (basedNumber bn[], unsigned int size) {
    unsigned int sum = 0;  
    for(unsigned i = 0; i < size; i++) {
        sum += base_convert(bn[i]); }                
    return sum; 
}


unsigned base_convert(basedNumber num) {
    unsigned p = strlen(num.arr) - 1;            //power of
    unsigned max = strlen(num.arr);              //max size for iteration
    unsigned sum = 0;
    for(unsigned i = 0; i < max; i++) {
        unsigned temp = 0;
        if(num.arr[i] >= 'A' && num.arr[i] <= 'Z') {
            temp = (int)num.arr[i] - 55; 
            sum += temp * pow(num.base, p); }
        else if(num.arr[i] >= 'a' && num.arr[i] <= 'z') {
            temp = (int)num.arr[i] - 87; 
            sum += temp * pow(num.base, p); }
        else if(num.arr[i] >= '0' && num.arr[i] <= '9') {
            temp = (int)num.arr[i] - 48;
            sum += temp * pow(num.base, p); }
        p--; }
    return sum;
}