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




class pvl2_students {
    
    /* data structure for a) - simple struct that gets pointed to by class' array */
    struct stud {
        unsigned regnum = 0;
        char* courses[30];
    };

    struct stud* registry[1000];
    unsigned count;
    
public:

    pvl2_students();                                        //constructor
    ~pvl2_students();                                       //destructor
    void pvl2_add_entry();                                  //task b)
    unsigned pvl2_validity_check(unsigned regnum);
    unsigned pvl2_search_entry(unsigned regnum, unsigned start, unsigned end);
    char* pvl2_add_courses();
    unsigned pvl2_stringsize(char buffer[]);
    void pvl2_stringcopy(char buffer[], char temp[]);
    unsigned pvl2_find_prev(unsigned regnum, unsigned previous);
    void pvl2_resort(stud* entry, unsigned pos);
    void pvl2_delete_entry(unsigned regnum);                //task d)
    bool pvl2_call_search(unsigned regnum);
};

#endif