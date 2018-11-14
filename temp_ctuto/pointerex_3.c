//implementation of function that swaps values of x and y 
//in main

#include <stdio.h>

void swap(int *x, int *y);

void swap(int *x, int *y)
{
  int hilf;
  hilf = *x;
  *x = *y;
  *y = hilf;
}

int main()
{
  int x=1, y=2;
  printf("x ist %d und y ist %d/n", x, y);
  swap(&x,&y);
  printf("x ist %d und y ist %d/n", x, y);
  return 0;
}
