supplementary file for morse parsing exercise in prog lab (algorithmen und programmierung)
task: parsing morse-code array recursively

code: “*- \*** \***”

``` c
/* to do:
- zeichen zählen, 
- Array anlegen 
- jedes Zeichen übersetzen */
char* parsemorse(const char* morsecode) {
    char* newString = (char*)calloc(counter(morsestring, 0) + 1, sizeof(char));
}

int counter(const char* morsecode, int i) {
    if(morsecode[i] == '\0')
        return 1;
    if(morsecode[i] == ' ')
        return 1 + counter(morsecode, i+1);
    return 0 + counter(morsecode, i+1);
}
void translate(const char* morsecode, char* newString, int i, int j) {
    if(morsecode[i] == '\0' || morsecode[i] == ' ') {
        if(morsecode[i-1] == '-' && morsecode[i-2] == '*')
            newString[j] = 'A';
        if(morsecode[i-1] == '*' && morsecode[i-2] == '*' && morsecode[i-3] == '*')
            newString[j] = 'S';
    }
    if(morsecode[i] == '\0')
        return;
    if(morsecode[i] == ' ') {
        return translate(morsecode, newString, i+1, i+2);
    }
    return translate(morsecode, newString, i+1, i+2);
}
```
    