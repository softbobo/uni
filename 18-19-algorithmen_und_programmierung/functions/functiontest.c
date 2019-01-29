//simple main program to test functions

#include <stdio.h>


unsigned int sum(unsigned int n);
unsigned int sum0dd(unsigned int n);
unsigned int digits(unsigned int n);
unsigned int checksum(unsigned int n);

int main() {
  unsigned int val = 5;
  printf("sum(%d) = %d\n", val, sum(val));
  printf("sum0dd(%d)= %d\n", val, sum0dd(val));
  printf("digits(%d) = %d\n", val, digits(val));
  printf("checksum(%d) = %d\n", val, checksum(val)); 
  return 0;
  }
