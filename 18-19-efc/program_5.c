//task 5 of paper 4
//softbobo 06/12/18

#include"unistd.h"
#include"stdio.h"

int main(){

  execlp("cal", "cal", NULL);			//executes file
  printf("The answer is %d\n", 42);
  return 0;
  }


