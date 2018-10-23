//simple main program to test functions.c

#include <stdio.h>

//function declaration - aka function call in python
//unsigned int sum(unsigned int n);
//unsigned int sum0dd(unsigned int n);
//unsigned int digits(unsigned int n);
unsigned int checksum(unsigned int n);


int main()
{
  //unsigned int n;
  //printf("Please enter a positive integer: ");
  //scanf('%d', &n);                              //scanf causes errors atm b/c of pointers
  //printf("sum(%d) = %d\n", n, sum(n));
  //printf("sum0dd(%d)= %d\n", '3', sum0dd(3));
  //printf("digits(%d) = %d\n", "24", digits(24));
  printf("checksum(%d) = %d\n", "24", checksum(24));
}
