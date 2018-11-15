/* AuP WS 2018/19, bewertete Aufgabe 3 */

int printf(const char * restrict, ...);
void *malloc(unsigned long);

const char *whirled(const char * const str); //task defined by function

unsigned long long input_length(const char * const p_str, unsigned long long length); 
const char* taz(const char* const str, char* new_str, unsigned long long i, unsigned long long pos);


int main(int carg, const char **varg){
//main() only to call whirled() and print result
    if (carg != 2) 
    return -1; 
    
    printf("Die verwürfelte Version von \"%s\" ist \"%s\".\n", 
    varg[1],whirled(varg[1]));
    
    return 0; 
}

const char *whirled(const char * const str)
{
    unsigned long long str_length = input_length(str,0); //determine input-length

    printf("kontrolle. eingegebener string: \"%s\", laenge des strings: \"%lld\"\n", str, str_length);
    //debug-feature - are args handed over correctly?
    
    char *new_str = (char*) malloc(str_length); //new array to twist that shit
    const char* output = taz(str, new_str, str_length, 0); //function call for result - check if correct
    
    return output;
}

unsigned long long input_length(const char * const p_str, unsigned long long length)
{   //func determines length of input string via recursion and returns it to whirled 
    
    if(p_str==0)
        return 0;
    if(p_str[length] == '\0')
        return length;
        //iterate through whole string, leave out end
    else 
        return input_length(p_str, length+1);
        //length++ doesn't work here - y?
    return 0;
}

const char* taz(const char* const str, char * new_str, unsigned long long i, unsigned long long pos)
{/*whirles that string 'round like taz the tasmanian devil
 takes input-string recursively; number of recursive steps is determined by index 'i'
 which is equivalent to the length of the input string 'str'. then iterates over every
 char of str, which points to the argv input. every letter gets a new position through
 variable pos, which starts from 0 and is the index of the output string 'str_new'.
 depending on the ascii code of respective char at every step, the new char gets assigned
 a new ascii value from the opposite of the alphabet. */
    printf("kontrolle. string 1: \"%s\". ", str);
    printf("index: \"%lld\".\n", i);
    //debug-feature: all args correct?
    
    if(i==0) //exit-feature
        return new_str;
    
    //for CAPITALS
    else if((65<=str[i]) && (str[i]<=90)){
        new_str[pos]=90+(65-(int)str[i]);
        //printf("step \"%lld\" current new string: \"%s\". \n", pos, new_str);
    }
    
    //for small letters 
    else if((97<=str[i]) && (str[i]<=122)){
        new_str[pos]=122+(97-(int)str[i]);
        //printf("step \"%lld\" current new string: \"%s\". \n", pos, new_str);
    }

    return taz(str, new_str, i-1, pos+1);
}