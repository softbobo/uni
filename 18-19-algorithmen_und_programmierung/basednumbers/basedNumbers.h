//header for basedNumbers as specified in respective pdf

#include <stdlib.h> 
typedef struct { 
    unsigned int base; 
    char *arr; } basedNumber; 
unsigned int sumOfBasedNumbers (basedNumber bn[], unsigned int size);