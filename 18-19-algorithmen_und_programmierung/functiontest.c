//simple main program to test functions

#include <stdio.h>

//function declaration - aka function call in python
//unsigned int sum(unsigned int n);
//unsigned int sum0dd(unsigned int n);
//unsigned int digits(unsigned int n);
//unsigned int checksum(unsigned int n);
unsigned long int squareroot (unsigned long int val);

int main()
{
  unsigned long int val = 16;
  //unsigned int n;
  //printf("Please enter a positive integer: ");
  //scanf('%d', &n);                              //scanf causes errors atm b/c of pointers
  //printf("sum(%d) = %d\n", n, sum(n));
  //printf("sum0dd(%d)= %d\n", '3', sum0dd(3));
  //printf("digits(%d) = %d\n", "24", digits(24));
  //printf("checksum(%d) = %d\n", "24", checksum(24));
  printf("The squareroot of %d is %d\n", val, squareroot(val));
  return 0;
  
  return 0;
  }
