/* AuP WS 2018/19, bewertete Aufgabe 3 */

int printf(const char * restrict, ...);
void *malloc(unsigned long);

const char *whirled(const char * const str); // Deklaration der Aufgabenfunktion
char taz(const char * const nltrs); /*function that substitutes all letters
with their counterparts from the opposite side of the alphabets*/
char length(const char *p_str[]);

int main(int carg, const char **varg)
{
    if (carg != 2) return -1; // error, sofern mehr als ein Parameter (zusätzlich zum Programmnamen), übergeben wird
    printf("Die verwürfelte Version von \"%s\" ist \"%s\".\n", varg[1], whirled(varg[1]));
    //gibt ergebnis aus
    
    return 0; // 0 bedeutet alles okay
}


//Mein Code ab hier

const char *whirled(const char * const str)

{
    unsigned long int strlen;
    strlen = length(str);
    printf("kontrolle:\"%s\", arraylänge: \"%d\"\n", str, sizeof(strlen)); //vor abgabe löschen

    //taz_str = taz(str[])


    
    //for reversion i need two pointers, one pointing to the first position
    //second to the last position of the array, that holds the string
    //the length of the string is stored in carg, so the last position
    //should be equal to the value of carg
    //i also need an array, that holds the inverted string

    
    
    
   
    //second invert charstring

    //third declare all char substitutions
    //substitution via a struct that holds all the subtitution pairs

    
    //probably have to do this char for char
    //fourth print out whole string

return str;
}
const char length(const char *p_str[])
{   
    printf("kontrolle: \"%p\"\n", p_str); //vor abgabe auskommentieren
    //unsigned long long length[];
    //if (length <= p_str)
    //return length+1;
    //else
     return (unsigned long long) length;
}

/*struct subs
    {
        char old;
        char new;
    } ltr = {A,B,C,D,E,F,G,I,J,K,L,M,N,O,P,
    Q,R,S,T,U,V,W,X,Y,Z,a,b,c,d,e,f,g,h,i,j,
    k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z}*/