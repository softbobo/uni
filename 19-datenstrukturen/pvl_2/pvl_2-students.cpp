/*
Robert Schulze
Matrikelnummer: 555625
May 2019
*/

/* functions declarations for 2nd lab assignment */

/* to do:
- implement pvl_2-add_student:
    write check for last entry in list and add var for highest regnum
*/

#include"pvl_2.h"

using namespace std;

class pvl2_students {

    stud* head = NULL;
    stud* tail = NULL;
    unsigned count = 0;
    const unsigned MAX = 1000;
    
public:

    pvl2_students();

    void pvl2_add_student() {
        stud* temp = new stud;
        unsigned regnum = 0;
        
        /* first copy data to new entry */
        cout << "Bitte Matrikelnummer des Studierenden eingeben: ";
        cin >> regnum;
        temp->regnum = regnum;
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
        }

    }

    void pvl2_add_course(char** courses) {
        return;
    }

    stud* pvl2_find_prev(stud* head) {
        stud* pos = NULL;

        return pos;
    }

    bool pvl2_is_registered(unsigned regnum);
    void pvl2_exmat(unsigned regnum);
    bool pvl2_regnum_is_valid(unsigned regnum);

};