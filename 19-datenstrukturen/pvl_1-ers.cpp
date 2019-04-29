//Robert Schulze; 29. Apr 2019; Matrikelnummer 555625

/* new try for first Data Structures lab assignment,
contains mostly recycled code from pvl_1-erassieve.cpp */

#include<iomanip>
#include<iostream>

using namespace std;

unsigned* ers_sieve(unsigned max, unsigned* output);

int main() {
    /* array is passed to the ers_sieve() function and passed back,
    filled with the desired values */
    unsigned* output = new unsigned[3];
    for(int i = 0; i <= 2; i++) { output[i] = 0; }

    unsigned const two = 2;

    cout << right << setw(8) << "N" << setw(8) << "P" << setw(8) << "S" << endl; 
    
    /* call function for 2^i with 2<=i<=20 and prints our return values */
    for(unsigned i = 2; i <= 20; i++) {

        unsigned max = 1;
        for(unsigned j = 0; j < i; j++) {
            max *= two;
        }

        output[0] = max;
        
        ers_sieve(max, output);
        cout << right << setw(8) << output[0] << setw(8) << output[1] << setw(8) << output[2] << endl; 
    }

    return 0;
}

/* sieve of erastosthenes implementation*/
unsigned* ers_sieve(unsigned max, unsigned* output) {
    
    /* allocate the array and 
    initialise all values of the array to true except the first two -
    vals, which are not prime, will be changed to false later */ 
    bool* sieve = new bool[max + 1];
    sieve[0] = false;
    sieve[1] = false;
    for(unsigned i = 2; i <= max; i++) { sieve[i] = true; }

    output[1] = 0;
    output[2] = 0;    

    /* main algo:
        - outermost loop iterates through the array until squareroot of its max
        is reached
        - next loop checks, if given value is is a prime number (only if val > 2
        obviously)
        - if testing for prime returned true, all multiples of given prime are 
        changed to false
       
       hints:
        - using (i*i <= max) as stop clause to approximate squareroot of max
    */
    for(unsigned i = 2; (i*i <= max); i++) {
        if(sieve[i] == true) {
            for(unsigned j = i*i; j <= max; j += i) {
                sieve[j] = false;
                output[2]++;
            }
        }
    }

    for(unsigned i = 0; i <= max; i++) {
        if(sieve[i] == true) { output[1]++; }
    }

    delete[] sieve;
    return output;
}