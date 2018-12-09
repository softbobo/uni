#include "stdaup.h"
#include "charset.h"

charset_t *charset_new(const char* elements){
//function tests for A-Z and a-z if char is present in 'elements' string

    char* alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
    'x', 'y', 'z'};

    charset_t chars = {};

    for(int i = 0; i <= 51; i++)                //test for every single letter of alphabet[]
        for(int j = 0; elements[j] != '\0'; j++)//iterate through whole input string
        {
            if(elements[j] == alphabet[i])      //if a letter is found shift chars[] 'one' bit and break
            {                                   //if it isn't present shift 'zero' bit
                chars >> 1;                     
                break;
            }
            else
                chars >> 0;
        }
    return charset chars;

}

/* hints:
- shifting algorithm for whole array https://stackoverflow.com/questions/10367616/bitwise-shifting-array-of-chars
- implementation of bit array (useful!) http://www.mathcs.emory.edu/~cheung/Courses/255/Syllabus/1-C-intro/bit-array.html
- implementation of bit array https://www.codeproject.com/Tips/53433/BitArray-in-C
- library for bit operations https://www.jjj.de/bitwizardry/bitwizardrypage.html
- lib function to compare two strings (for task 2) http://pubs.opengroup.org/onlinepubs/9699919799/functions/strspn.html
- bit twiddling hacks http://graphics.stanford.edu/~seander/bithacks.html
- collection of low lever algorithms http://aggregate.org/MAGIC/
- the bit twiddler https://bits.stephan-brumme.com/

