#include "stdaup.h"
#include "charset.h"

unsigned long long input_length(const char* input, unsigned long long count);
//helper for task 1

charset_t* union_func(charset_t* s1, const charset_t* s2);
charset_t* cut_func(charset_t* s1, const charset_t* s2);
charset_t* symdiff_func(charset_t* s1, const charset_t* s2);
//helpers for task 2

charset_t *charset_new(const char* elements)
{
//for task 1
//still to do:
//populate output in correct order
//implement correct test cases in charset_test
    const char alphabet[53] = 
    {122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97,
    90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65};
    /*{'z','y','x','w','v','u','t','s','r','q','p','o','n','m','l','k','j','i','h',
    'g','f','e','d','c','b','a','Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K',
    'J','I','H','G','F','E','D','C','B','A'};*/
    //lookup table for alphabet is in reversed order, since chars[] is filled up beginning with the 
    //LSB of the last byte

    struct charset *chars;
    chars = malloc(sizeof(struct charset));
    int len = input_length(elements, 0);
    printf("length of input string is: %d\n", len);
    printf("input string is: %s\n", elements);
    
    for(int i = 0; i <= 51; i++)                //test for every single letter of alphabet[]
        {
        int byte_pos = (i/8);                   //perform bitshift for the right byte of the array, beginning from the last
        printf("current byte: %d, letter: %c\n", byte_pos, alphabet[i]); //debug-print
        for(int j = 0; j <= len; j++) //iterate through whole input string
        {
            printf("position in input string: %c\n", elements[j]); //debug-print
            if(elements[j] == alphabet[i])      //if a letter is found shift chars[] 'one' bit to th right and break
            {                                   
                chars->bits[byte_pos] >>= 1; 
                printf("Character added: %c, must be equivalent to alphabet: %c\n", elements[j], alphabet[i]);
                //debug-statement          
                break;
            }
            else if(elements[j] == '\0')
            {
                chars->bits[byte_pos] >>= 0;           //fill a 0 if char isn't present
                printf("current pos in alphabet: %c, added a 0\n", alphabet[i]);
                //debug-statement
            }
        }
    }
    return chars;

}

unsigned long long input_length(const char* input, unsigned long long count)
//determines length of input string in task 1 including terminating '\0'
{
    for(unsigned long long i = 0; input[i] != '\0'; i++)
        count++;

    return count;
}

int charset_op(charset_t* s1, const charset_t* s2, csopt_t op)
{
//for task 2
    printf("string 1: %s, string 2: %s\n", s1, s2);     //debug

    if(s1 == NULL || s2 == NULL)            //check for Nullpointers
        return -1;
    else
    {
        switch(op)                          //switch for given enum constants, store result in s1
        {                                   
            case CS_UNION:      union_func(s1, s2);
                                break;
            case CS_CUT:        cut_func(s1, s2);
                                break;
            case CS_SYMDIFF:    symdiff_func(s1, s2);
                                break;
            default:            return -1;
        }
    }
    return 0; 
}

charset_t* union_func(charset_t* s1, const charset_t* s2)
{
//calculates union of both operands

    for(int i = 0; i <= 6; i++)
    {
        s1->bits[i] &= s2->bits[i];
    }
    return s1;
}

charset_t* cut_func(charset_t* s1, const charset_t* s2)
{
//calculates intersection of both operands
    for(int i = 0; i <= 6; i++)
    {
        s1->bits[i] |= s2->bits[i];
    }
    return s1;
}

charset_t* symdiff_func(charset_t* s1, const charset_t* s2)
{
//calculates intersection of both operands
    for(int i = 0; i <= 6; i++)
    {
        s1->bits[i] ^= s2->bits[i];
    }
    return s1;
}

char *charset_tos(const charset_t* s)
{
/*function for task 3, searches input str for chars, populates output str with found chars
alphabetically, capitals first*/

    static char output[8] = {0};

    char lookup[53] = {0};

    int i, j;
    for(i = 0, j = 65; i < 52; i += 2)    //populates array w/ capitals
    {
        lookup[i] = j;
        printf("char added: %c , pos: %d\n", j, i);
        j++;
    }
    for(i = 1, j = 97; i < 52; i += 2)    //populates array w/ small letters
    {
        lookup[i] = j;
        printf("char added: %c , pos: %d\n", j, i);
        j++;
    }
    int l = 0;
    for(i = 0; lookup[i] != 0; i++)
    {
        for(j = 0; s->bits[j] != 0; j++)
        {
            if(lookup[i] == s->bits[j])
            {
                output[l] = s->bits[j];
                printf("position in output: %d, char added to output: %c\n",l , output[l]);
                l++;
            }
        }
    }
    return output;
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


