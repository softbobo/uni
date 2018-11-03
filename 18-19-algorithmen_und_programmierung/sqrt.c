//heron test
//#include <stdio.h>

unsigned long int squareroot(unsigned long int val);
unsigned long int helproot();

//int main(){
//    printf("Die Wurzel aus %lu ist %lu. \n", 
//    (unsigned long)174897, squareroot((unsigned long)174897));
//    return 0;
//}

unsigned long int squareroot(unsigned long int val)
{
    if(val == 0)  
    return 0;
    
    else return helproot(1, val);
}


unsigned long int helproot(unsigned long int x, unsigned long y)
{
    x = (x+(y/x))/2;
    
    if(x*x<=y)
    return x;
    
    else return helproot(x, y);
}