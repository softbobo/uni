// Robert Schulze 26 April 2019

/* header file for pvl_1-erassieve.cpp,
contains function declarations */

#include<iostream>

uint64_t ers_input();
bool* ers_strike(bool sieve[], uint64_t max, uint64_t* p_strike_count);
bool ers_is_prime(uint64_t num);
uint64_t ers_count_prime(bool sieve[], uint64_t max);
