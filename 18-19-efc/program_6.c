//small code from exercise, can be found on paper 4
//softbobo 06/12/18

#include"stdlib.h"
#include"stdio.h"
#include"unistd.h"
#include"sys/types.h"		/*doesn't compile w/o this header b/c of pid_t data type
				probably purpose of this code is to show that?*/

int main(){
  pid_t p;
  p = fork();
  if(p == 0)
    printf("Null\n");
  else
    printf("Not Null\n");

  return 0;
  }
