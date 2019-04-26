//Robert Schulze 26 April 2019

/*
First lab assignment for the data structures lecture. Task specified in pdf:
a)  - write a function, that takes 'n' as an arg 
    - returns count of primes in the interval [2,n] - 'p'
    - also returns 's' - count of stroke numbers
b)  - put that into a program (with main() and stuff) that takes 2^i (i <= 20)
    and gives that to the function a)
    - prints out the return values of the a) function right-bound, newline per val
c)  - plot the whole thing: graph of p and s in correlation to n (make pdf)
d)  - find a function that finds the minimal upper border in time complexity
    of function a)
*/

/* catch:
    - set max (uintmax) and min (2) for n 

*/

/* algo:
    - main() function:
        - allocates bool-array for n vals (and its pointer to pass it around)
        - initialize whole array with false - true will all strokes
    - input() function:
        - allocates var and pointer for n
        - checks recursively for validity of input value
    - 
*/

/* questions:
    - plotting method doesn't matter? or is GNUPLOT mandatory?
    - may we use libs (like cmath)?
*/

#include<iostream>
#include"pvl_1-erassieve.h"

using namespace std;

int main() {

}

/* simple: function takes user input and checks, if the entered value is 
within the bounds of 8-byte unsigned integers (at least two) */
uint64_t* ers_input() {
    uint64_t n = 0;
    uint64_t* p_n = &n;

    cout << "Please enter the maximum value n" << endl;
    cin >> n;

    if(n < 2 || n > UINT64_MAX) {
        cout << "Error. Entered value must be greater than two and ";
        cout << "smaller than 18446744073709551615." << endl;
        return ers_input();
    }

    return p_n;
}