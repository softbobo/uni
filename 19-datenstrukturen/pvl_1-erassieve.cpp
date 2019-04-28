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
    - ers_strike():
        - heart of this program, finds all primes in the gven interval
        - 
    - ers_prime_check():
        - checks, if a given number is prime or not
    - ers_output() function:
        - calls ers_count_prime(), return val is p 
        - prints n, p, s, rightbound 
    - ers_count_prime() function:
        - counts all the true-vals in the array, returns their count

        
*/

/* questions:
    - plotting method doesn't matter? or is GNUPLOT mandatory?
    - may we use libs (like cmath)?
    - what is meant by "für jedes n ist jeweils eine neue zeile zu beginnen" (b)?
    - "logarithmische skalen" (c)? 
*/

#include<iostream>
#include"pvl_1-erassieve.h"
#include<cmath>

using namespace std;

int main() {
    uint64_t max = ers_input() + 1;
    bool* sieve = new bool[max];

    /* initialise all values of the array to true except the first two -
    vals, which are not prime, will be changed to false later in ers_strike() */ 
    sieve[0] = false;
    sieve[1] = false;
    for(uint64_t i = 2; i <= max; i++) { sieve[i] = true; }

    ers_strike(sieve, max);

    delete[] sieve;
    return 0;
}

/* simple: function takes user input and checks, if the entered value is 
within the bounds of 8-byte unsigned integers (at least two) */
uint64_t ers_input() {
    uint64_t max = 0;

    cout << "Please enter the maximum value n" << endl;
    cin >> max;

    if(max < 2 || max > UINT64_MAX) {
        cout << "Error. Entered value must be greater than two and ";
        cout << "smaller than 18446744073709551615." << endl;
        return ers_input();
    }

    return max;
}

/* probably single most important function in here:
    - counts the number of strikes (multiples count multiple times)

 */
bool* ers_strike(bool sieve[], uint64_t max) {
    uint64_t strike_count = 0;

    for(uint64_t i = 2; i <= sqrt(max); i++) {
        if(ers_is_prime(i)) {
            for(uint64_t j = i*i; j <= sqrt(max); (j+i)) {
                sieve[j] = false;
                strike_count++;
            }
        }
    }
    cout << "debug. count of strikethroughs is: " << strike_count << endl;     //temp. to remove later
    return sieve;
}

/* checks, if passed arg is prime; no need to check for args < 2, since no 
smaller ints are going to be passed by ers_strike() (calling function) */
bool ers_is_prime(uint64_t num) {
    if(num == 2) { return true; }
    else {
        for(uint64_t i = 2; i <= sqrt(num); i++) {
            if(num % i == 0) { return false; }
        }
    }
    cout << "debug. " << num << " is prime." << endl;               //temp. gonna be removed later
    return true;
}


/* counts all the 'trues' in the array - this is the number of primes in the
given interval */
uint64_t ers_count_prime(bool sieve[], uint64_t max) {
    uint64_t count = 0;
    
    for(uint64_t i = 2; i <= max; i++) { if(sieve[i]) count++; }

    cout << "debug: count of primes: " << count << endl;                //temp print, removed later
    return count;
}