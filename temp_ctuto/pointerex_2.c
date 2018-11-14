//trying out the examples for explanatory code on pointers from the reading

#include <stdio.h>

void sideeffect(int *p);

int main()
{
int x=42;
printf("Der Wert von x beträgt %d.\n", x);
sideeffect(&x);
printf("Der neue Wert von x beträgt %d.\n", x);
return 0;
}

void sideeffect(int *p)
{
*p=23;
}
