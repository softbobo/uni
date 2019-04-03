//pointer arithmetics - guess, what is put out in the end
//softbobo 190403

#include<iostream>

using namespace std;

int main() {
    int a = 1, b = 2,  c = 3;
    
    int* pa = &a; 
    int* pb = &b;
    int* pc = &c;

                    //guesses:
    *pa = *pb;      //value of b gets written into address of a (a becomes '2')
    pb = pc;        //pb gets the adress referenced in pc (b becomes '3')
    *pb = a-1;      //value of b ('3' after preceding operation) gets decremented by 1 - is 2
    b = *pc + 3;    //b becomes 4 b/c c is 1 b/c pb points to c after operation 2

    cout << a << " "<< b << " " << c << endl;
    cout << *pa << " " << *pb << " " << *pc  << endl;

    return 0;
}