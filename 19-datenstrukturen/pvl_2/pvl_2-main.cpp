/*
Robert Schulze
Matrikelnummer: 555625
May 2019
*/

/* Second lab assignment for data structures. Tasks:
- design a data structure w/ an array of pointer [1000] pointing to a structure
w/ unique number and courses (30 max - array of strings) of students
- write an input function for student data
- function, that finds a student with given number, bonus points for solutions
faster than O(n)
- function, that deletes a student's entry, musn't leave null pointers in between
entries
- interface with options to choose from aforem functions

important:
- strings must use only as much space as necessary
- delete[] allocated memory
- libfuncs only for input and output
*/

/* to do:
*/

using namespace std;

#include"pvl_2.h"
#include"pvl_2-menu.h"

int main() {
    
    pvl_2_menu();

    return 0;
}