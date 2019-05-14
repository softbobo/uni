/*
Robert Schulze
Matrikelnummer: 555625
May 2019
*/

/* functions declarations for 2nd lab assignment */

/* to do:
- implement pvl_2-add_student:
    - write check for validity of regnum
    - write check for last entry in list and add var for highest regnum
- change name of pvl2_exmat() to pvl2_delete() for clarity
*/

#include"pvl_2.h"

using namespace std;


pvl2_students::pvl2_students() {

}                          

void pvl2_students::pvl2_add_student() {
    stud* temp = new stud;
        
    /* first copy data to new entry */
    unsigned regnum = 0;
    cout << "Bitte Matrikelnummer des Studierenden eingeben: ";
    cin >> regnum;

    /* this is a bit hacky: passes regnum to validity check, gets back same num 
    if valid, else gets back a new one from the validity check */
    temp->regnum = pvl2_regnum_is_valid(regnum, 'R');
    pvl2_add_course(temp->courses);

    /* then integrate list entry sorted */
    /* if entry is the first in the list */
    if(head == NULL) {
        head = temp;
        tail = temp;
        count += 1;
    }
    /* for all other entries no need to check for NULL, already done in previous if-statement */
    else {
        stud* pos = pvl2_find_prev(head);
        
        // re-route tail if previous entry is the last of the list
        if(pos->next == NULL) {
            tail = temp;
        }
        
        temp->prev = pos;
        temp->next = pos->next;
        pos->next->prev = temp;
        pos->next = temp;
        
        count += 1;
    }

}

/* needs to work like this:
1. enter big for-loop to count up to 30 
2. allocate char variable, enter while-loop with getchar()
3. write string to memory and direct pointer in array to it
4. ask user for next input
*/
void pvl2_students::pvl2_add_course(char** courses) {
        
        
    return;
}

stud* pvl2_students::pvl2_find_prev(stud* head) {
    stud* pos = NULL;

    return pos;
}

bool pvl2_students::pvl2_is_registered(unsigned regnum) {
    return false;
}
void pvl2_students::pvl2_exmat(unsigned regnum) {

}

/* this gotta work like this:
1. checks if regnum is within given borders
2. if yes, passes regnum to next function, determined via option and switch statement
3. if no, prints out error message, lets user enter new regnum and calls 
itself recursively with new regnum
4. add escape option to end program?
*/
unsigned pvl2_students::pvl2_regnum_is_valid(unsigned regnum, char opt) {
    
    if(regnum > 0 && regnum < 1000000) {
        switch (opt) {
        case 'R':
            return regnum;
        case 'S':
            pvl2_is_registered(regnum);
            break;
        case 'L':
            pvl2_exmat(regnum);
            break;
        default:
            break;
        }
    }
    
    return regnum;
}
