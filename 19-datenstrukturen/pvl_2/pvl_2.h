/*
Robert Schulze
Matrikelnummer: 555625
May 2019
*/

/* header for second lab assignment */

#ifndef PVL_2_H
#define PVL_2_H

#include<iostream>

/* data structure for a) - doubly linked list that contains all the
student data */
struct stud {
    unsigned regnum = 0;
    char* courses[30];
    stud* prev = NULL;
    stud* next = NULL;
};

class pvl2_students {

    stud* head = NULL;
    unsigned count = 0;
    const unsigned MAX = 1000;
    
public:

    pvl2_students();
    void pvl2_add_student(unsigned regnum, char** courses);
    bool pvl2_is_registered(unsigned regnum);
    void pvl2_exmat(unsigned regnum);
    bool pvl2_regnum_is_valid(unsigned regnum);

};

#endif