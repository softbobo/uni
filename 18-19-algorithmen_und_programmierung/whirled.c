
/* AuP WS 2018/19, bewertete Aufgabe 3 */

int printf(const char * restrict, ...);
void *malloc(unsigned long);

const char *whirled(const char * const str); //task defined by function

unsigned long long input_length(const char * const p_str, unsigned long long length); 
const char* taz(const char* const old_str, char* new_str, unsigned long long i, unsigned long long j);


int main(int carg, const char **varg){
//main() only to call whirled() and print result
    if (carg != 2) 
    return -1; 
    
    printf("Die verwürfelte Version von \"%s\" ist \"%s\".\n", varg[1], whirled(varg[1]));
    return 0; 
}


const char *whirled(const char * const str)
{
    unsigned long long len = input_length(str,0); //determine input-length

    //printf("kontrolle. eingegebener string: \"%s\", laenge des strings: \"%lld\"\n", str, len);
    //debug-feature - are args handed over correctly?
    
    char *new_str = (char*)malloc(len+1); //new array to twist that shit
    const char* output = taz(str, new_str, len-1, 0); //function call for result - check if correct
    
    return output;
}

unsigned long long input_length(const char * const p_str, unsigned long long length)
{   //func determines length of input string via recursion and returns it to whirled 
    
    if(p_str[length] == '\0')
        return length;
        //iterate through whole string, leave out end
    else 
        return input_length(p_str, length+1);
    return 0;
}

const char* taz(const char* const old_str, char * new_str, unsigned long long i, unsigned long long j)
{/*whirles that string 'round like taz the tasmanian devil
 takes input-string recursively; number of recursive steps is determined by index 'i'
 which is equivalent to the length of the input string 'str'. then iterates over every
 char of str, which points to the argv input. every letter gets a new position through
 variable j, which starts from 0 and is the index of the output string 'str_new'.
 depending on the ascii code of respective char at every step, the new char gets assigned
 a new ascii value from the opposite of the alphabet. */
    //printf("To taz: \"%s\", index: %llu, char at index: %c\n", old_str, i, old_str[i]);
    //debug-feature: all args correct?
    
    //exit-feature
    if(old_str[j]==0){ 
        return new_str;
    }//for CAPITALS
    else if(old_str[i] >= 65 && old_str[i] <= 90){
        new_str[j] = 65 + (90 - old_str[i]);
        //printf("step \"%llu\" current new char: %c. \n", j, new_str[j]);
    }//for small letters 
    else if(old_str[i] >= 97 && old_str[i] <= 122){
        new_str[j] = 97 + (122 - old_str[i]);
        //printf("step \"%llu\" current new char: %c. \n", j, new_str[j]);
    }//all other chars
    else{
        new_str[j] = old_str[i];
    }
    return taz(old_str, new_str, i-1, j+1);
}