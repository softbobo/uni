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
#include<iomanip>

using namespace std;

int main() {
    uint64_t max = ers_input();
    bool* sieve = new bool[max + 1];

    /* initialise all values of the array to true except the first two -
    vals, which are not prime, will be changed to false later in ers_strike() */ 
    sieve[0] = false;
    sieve[1] = false;
    for(uint64_t i = 2; i <= max; i++) { sieve[i] = true; }

    uint64_t strike_count = 0;
    uint64_t* p_strike_count = &strike_count;

    ers_strike(sieve, max, p_strike_count);

    /* setw(7) is because we ought to test up to 2^20, ergo 1048576 */
    cout << right << setw(7) << "N" << setw(7) << "P" << setw(7) << "S" << endl; 
    ers_output(sieve, max, p_strike_count);

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
    - checks all the values in the array if they are prime
    - if yes, changes val of their multiples to false
*/
bool* ers_strike(bool sieve[], uint64_t max, uint64_t* p_strike_count) {
    /* works as follows:
        - outer loop enters for every single number starting at two
        - checks, if number is prime
        - if yes, inner loop is entered, all multiples of i are set to false
        - for every number set to false, strike-count gets incremented
    */
    for(uint64_t i = 2; i <= sqrt(max); i++) {
        if(ers_is_prime(i)) {
            for(uint64_t j = i*i; j <= max; j+=i) {
                sieve[j] = false;
                (*p_strike_count)++;
            }
        }
    }
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
    return true;
}

/* this is going to be the properly formatted output later */
void ers_output(bool sieve[], uint64_t max, uint64_t* p_strike_count) {
    uint64_t prime_count = ers_count_prime(sieve, max);

    cout << right << setw(7) << max << setw(7) << prime_count << setw(7) << *p_strike_count << endl;
}


/* counts all the 'trues' in the array - this is the number of primes in the
given interval */
uint64_t ers_count_prime(bool sieve[], uint64_t max) {
    uint64_t count = 0;
    
    for(uint64_t i = 2; i <= max; i++) { if(sieve[i]) count++; }

    return count;
}