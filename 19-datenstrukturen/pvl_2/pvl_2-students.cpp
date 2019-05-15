/*
Robert Schulze
Matrikelnummer: 555625
May 2019
*/

/* functions declarations for 2nd lab assignment */

/* to do:
- check bacl on add_course, doubt it will work like that
- change name of pvl2_exmat() to pvl2_delete() for clarity
- check back in break/continue clause in add_course() for error input
*/

#include"pvl_2.h"
#include"pvl_2-menu.h"

using namespace std;


pvl2_students::pvl2_students() {
    
    for(int i = 0; i < 1000; i++) {
        registry[i] = NULL;
    }
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
    
    /* do this, then that:
    1. write input message
    2. read getline() from cli
    3. determine length of input in buffer
    4. allocate string this length +1 
    5. write buffer to new string
    6. direct pointer at prosition i to the string
    7. ask, if more input should be given
    */
    for(unsigned i = 0; i < 30; i++) {
        
        cout << "Bitte Namen des Kurses eingeben und mit Enter bestätigen" << endl;

        char* buffer = NULL;
        size_t size = 10000;
        cin.getline(buffer, size);
        cout << "debug. entered course was: " << buffer << endl;

        courses[i] = buffer;

        char answer = 0;

        cout << "Weiteren Kurs hinzufügen? [J/N]" << endl;
        cin >> answer;
        if(answer == 'N') { break; }
        else if(answer == 'J') { continue; }
    }
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

    else {
        cout << "Unzulaessige Eingabe! Die Matrikelnummer muss sich zwischen " <<
            "1 und 999999 befinden! " << endl;

        pvl_2_menu();
    }
}
