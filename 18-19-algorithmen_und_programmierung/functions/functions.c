//implements the functions necessary for task 005

//sum of all numbers 1 to n
unsigned int sum(unsigned int n)
{
  if(n != 0)
  return n + sum(n-1);
  else return n;
}

//sum of first odd numbers in n
unsigned int sum0dd(unsigned int n)
{
  if(n != 0 && n % 2 == 1)
  return n + sum0dd(n-1);
  else if(n != 0 && n % 2 == 0)
  return n-1;
  else return n;
}


//number of digits of n
unsigned int digits(unsigned int n)
{
  unsigned int count = 0;
  while (n != 0)
  {
  n /= 10;
  ++count;
  
  }
  return count;
}

//checksum of n
unsigned int checksum(unsigned int n)
{
  int check = 0;
  while(n != 0)
  {
    check += n % 10;
    n /= 10;
  }
  return check;
}
