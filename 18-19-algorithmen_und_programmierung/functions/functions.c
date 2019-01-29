//implements the functions necessary for task 005

//sum of all numbers 1 to n
unsigned int sum(unsigned int n) {
  for(unsigned i = n-1; i > 0; i--)
    n += i;
  return n; 
}

//sum of odd number from 1 to n
unsigned int sum0dd(unsigned int n) {
  for(unsigned i = n-1; i > 0; i--)
    if(i % 2 == 1)
      n += i;
  return n;
}


//number of digits of n
unsigned int digits(unsigned int n) {
  unsigned int count = 0;
  while (n != 0) {
  n /= 10;
  ++count;
  }
  return count;
}

//checksum of n
unsigned int checksum(unsigned int n) {
  int check = 0;
  while(n != 0) {
    check += n % 10;
    n /= 10;
  }
  return check;
}
