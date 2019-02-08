/*task from past uni exam, function is supposed to take two strings and should return if PATTERN
is found in TEXT, and if yes, return an array with the start position(s) of the string in string.
function from string.h are not allowed*/

//softbobo 190130

/* implementation in pseudocode:
REQUIRE: PATTERN, TEXT
ENSURE: if PATTERN in TEXT return position in result

result
temp
length_t <- length of TEXT
length_p <- length of PATTERN             
j <- 0, k <- 0                             //iterator variables for pattern, result

for i <- 0, ... , i <= length_t
    if (TEXT at i) = (PATTERN at (j = 0)) or (TEXT at i) = '?'
        temp <- i
        increment j
    if (TEXT at i) = (PATTERN at (j != 0)) or (TEXT at i) = '?'
        increment j
    if (TEXT at i) = (PATTERN at (j = length_p)) or ((TEXT at i) = '?' and (j = length_p))
        result at k <- temp
        j <- 0
        increment k
    else
        j <- 0
end for
return result
*/

/* time complexity in Big O:
Die Funktion hat 
*/

// implementation in C:

#include"grp.h"

int* grep(const char* pattern, const char* text) {
    int length_pattern = lngth(pattern);
    int length_text = lngth(text);
    int temp;
    int j = 0, k = 0;
    int* result = (int*)malloc((length_text/length_pattern) * sizeof(int));

    for(int i = 0; i < (length_text + 1); i++) {
        if(text[i] == pattern[j] || text[i] == '?') {
            if(j == 0) {
                temp = i; }
            else if(j == length_pattern) {
                result[k] = temp;
                k++;
            }
            j++;
        }
        else {
            j = 0;
            temp = 0;
        }
    }
    return result;
}

int lngth(const char* string) {
    int length = 0;
    for(int i = 0; string[i] != '\0'; i++)
        length++;
    return length;
}
