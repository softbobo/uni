/*
Robert Schulze
Matrikelnummer: 555625
May 2019
*/

/* functions declarations for 2nd lab assignment */

/* to do:
- re-implement add_student for array
- re-implement regnum validity check (unique && within bounds)
- implement binary search function
-
- implement destructor that explicitly deletes all entries and array  
*/

#include"pvl_2.h"
#include"pvl_2-menu.h"

using namespace std;


pvl2_students::pvl2_students() {
    
    for(int i = 0; i < 1000; i++) {
        registry[i] = NULL;
    }
}                          

void pvl2_students::pvl2_add_entry() {
    stud* temp = new stud;
        
    /* first copy data to new entry */
    unsigned regnum = 0;
    cout << "Bitte Matrikelnummer des Studierenden eingeben: ";
    cin >> regnum;
}

