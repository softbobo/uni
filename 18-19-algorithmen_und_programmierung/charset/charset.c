#include "stdaup.h"
#include "charset.h"

unsigned long long input_length(const char* input, unsigned long long count);

charset_t *charset_new(const char* elements){
//function tests for A-Z and a-z if char is present in 'elements' string

    const char alphabet[53] = 
    {122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97,
    90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65};
    /*{'z','y','x','w','v','u','t','s','r','q','p','o','n','m','l','k','j','i','h',
    'g','f','e','d','c','b','a','Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K',
    'J','I','H','G','F','E','D','C','B','A'};*/
    //lookup table for alphabet is in reversed order, since chars[] is filled up beginning with the 
    //LSB of the last byte

    charset_t chars[] = malloc(sizeof(alphabet)); //FREE THIS LATER!
    char *p_chars;
    p_chars = chars;                            //pointer for value-return
    unsigned long long len = input_length(elements, 0); 

    for(int i = 0; i <= 51; i++)                //test for every single letter of alphabet[]
        {
        int byte_pos = (i/8) + (7-i/8);         //perform bitshift for the right byte of the array, beginning from the last
        printf("current byte: %d", byte_pos);   //debug-print
        for(int j = 0; elements[j] <= len; j++)//iterate through whole input string
        {
            if(elements[j] == alphabet[i])      //if a letter is found shift chars[] 'one' bit and break
            {                                   //if it isn't present shift 'zero' bit
                chars[byte_pos] >>= 1; 
                printf("Character added: %c, must be equivalent to alphabet: %c\n", elements[j], alphabet[i]);
                //debug-statement          
                break;
            }
            else if(elements[j] == '\0')
                chars[byte_pos] >>= 0;           //fill a 0 if char isn't present
                printf("current pos in alphabet: %c, added a 0\n", alphabet[i]);
                //debug-statement
            }
    }
    return p_chars;

}

unsigned long long input_length(const char* input, unsigned long long count)
//determines length of input string including terminating '/0'
{
    for(unsigned long long i = 0; input[i] != '\0'; i++)
        count++;

    return count += 1;
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
*/


