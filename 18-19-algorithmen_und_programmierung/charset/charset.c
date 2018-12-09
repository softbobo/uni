#include "stdaup.h"
#include "charset.h"

charset_t *charset_new(const char* elements){
//function tests for A-Z and a-z if char is present in 'elements' string

    char* alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
    'x', 'y', 'z'};

    charset_t chars = {};

    for(int i = 0; i <= 51; i++)
        for(int j = 0; elements[j] != '\0'; j++)
        {
            if(elements[j])
        }

}