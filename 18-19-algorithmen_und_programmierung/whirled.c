/* AuP WS 2018/19, bewertete Aufgabe 3 */

int printf(const char * restrict, ...);
void *malloc(unsigned long);

const char *whirled(const char * const str); 
unsigned long long input_length(const char * const p_str, unsigned long long length);


int main(int carg, const char **varg){

    if (carg != 2) return -1; 
    printf("Die verwürfelte Version von \"%s\" ist \"%s\".\n", 
    varg[1],whirled(varg[1]));
    return 0; 
}

const char *whirled(const char * const str)
{
    unsigned long long str_length = input_length(str[0], 0);
    printf("kontrolle. eingegebener string: \"%s\", laenge des strings: \"%lld\"\n", str, str_length);
    //kontroll-ausgabe -> ist string korrekt übergeben worden und stimmt seine länge?
    return 0;
}

unsigned long long input_length(const char * const p_str, unsigned long long length)

{
    const char *copy_str[] = p_str;
    // SEG FAULT DA VERMUTLICH ZEIGER FALSCH INITIALISIERT
    //const char * copy_str = p_str;
    if(*copy_str[] != '\0')
    return  input_length(copy_str, length+1);
    else return  length;

}