/*
Robert Schulze
Matrikelnummer: 555625
May 2019
*/

/* header for second lab assignment */

/* Functions I need:
- constructor
- destructor
- search entry
- add entry
- regnum validity check
- delete entry
- add courses
- 

*/

#ifndef PVL_2_H
#define PVL_2_H

#include<iostream>

/* data structure for a) - simple struct that gets pointed to by class' array */
struct stud {
    unsigned regnum = 0;
    char* courses[30];
};

class pvl2_students {

    stud* registry[1000];
    
public:

    pvl2_students();                                        //constructor
    void pvl2_add_entry();                                  //task b)


};

#endif