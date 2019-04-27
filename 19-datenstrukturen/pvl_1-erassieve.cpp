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
    - ers_input() function:
        - allocates var for n
        - checks recursively for validity of input value
    - ers_count_prime() function:
        - counts all the true-vals in the array, returns their count
*/

/* questions:
    - plotting method doesn't matter? or is GNUPLOT mandatory?
    - may we use libs (like cmath)?
*/

#include<iostream>
#include"pvl_1-erassieve.h"

using namespace std;

int main() {
    uint64_t n = ers_input();
    bool* sieve = new bool[n];

    for(uint64_t i = 0; i <= n; i++) { sieve[i] = false; }

    ers_count_prime(sieve, n);

    return 0;
}

/* simple: function takes user input and checks, if the entered value is 
within the bounds of 8-byte unsigned integers (at least two) */
uint64_t ers_input() {
    uint64_t n = 0;

    cout << "Please enter the maximum value n" << endl;
    cin >> n;

    if(n < 2 || n > UINT64_MAX) {
        cout << "Error. Entered value must be greater than two and ";
        cout << "smaller than 18446744073709551615." << endl;
        return ers_input();
    }

    return n;
}

uint64_t ers_count_prime(bool sieve[], uint64_t n) {
    uint64_t count = 0;
    
    for(uint64_t i = 2; i <= n; i++) { if(sieve[i]) count++; }

    cout << "debug: count of primes: " << count << endl;
    return count;
}