/*
Robert Schulze
Matrikelnummer: 555625
May 2019
*/

/* header for second lab assignment */

#ifndef PVL_2_H
#define PVL_2_H

class pvl2_students {

public:

    pvl2_students();
    void pvl2_add_student(unsigned regnum, char** courses);
    bool pvl2_is_registered(unsigned regnum);
    void pvl2_exmat(unsigned regnum);

};

#endif