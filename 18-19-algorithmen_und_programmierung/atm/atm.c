//facultatory task 060 - simulation of an atm
//write a function, that takes positive ints up to 2000 from the CLI
//and outputs the splitup in 50, 20, 10, and 5 euro bills
//(min amount of bills to be displayed)
//written by softbobo 03/12/2018

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
  if(argc != 2)
    return -1;                        //exactly one arg permitted
  int req = atoi(argv[1]);                  //read in required amount
  int a,b,c,d;                        //values for amount of every bill
  int rest = 0;                          //remaining amount after each division
  if(req <= 0 || req >= 2000 || req % 5 != 0){
    printf("%d \n", 0);
    return 0;
  }
  else{
    a = req/50;
    rest = req%50;
    b = rest/20;
    rest = rest%20;
    c = rest/10;
    rest = rest%10;
    d = rest/5;
    }

  printf("%d*50-EUR %d*20-EUR %d*10-EUR %d*5-EUR\n", a,b,c,d);
  return 0;
}
