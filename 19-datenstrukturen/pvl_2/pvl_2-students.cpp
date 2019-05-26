/*
Robert Schulze
Matrikelnummer: 555625
May 2019
*/

/* functions declarations for 2nd lab assignment */

/* to do:
- check for course assignment after returning from add_course() to add_entry()

*/

#include"pvl_2.h"
#include"pvl_2-menu.h"

using namespace std;


pvl2_students::pvl2_students() {
    
    for(int i = 0; i < 1000; i++) {
        registry[i] = NULL;
    }

    count = 0;
}  

pvl2_students::~pvl2_students() {
    for(unsigned i = 0; i < count; i++) {
        delete registry[i];
    }
}

void pvl2_students::pvl2_add_entry() {
    stud* temp = new stud;
        
    /* first copy regnum to new entry */
    unsigned regnum = 0;
    cout << "Bitte Matrikelnummer des Studierenden eingeben: ";
    cin >> regnum;
    temp->regnum = pvl2_validity_check(regnum);

    /* next is adding courses to the new entry*/
    for(int i = 1; i < 31; i++) {
        char answer = 0;
        cout << "Kurs Nr. " << i << " eingeben? (J/N)" << endl;
        cin >> answer;
        cin.ignore();
        if(answer == 'J') { temp->courses[i-1] = pvl2_add_courses(); }
        else { break; }
    }

    /* now insert the entry sorted */
    if(count == 0) {
        registry[0] = temp;
    }
    else {
        unsigned pos = pvl2_find_prev(regnum, regnum-1) + 1;
        pvl2_resort(temp, pos);
    }
    count += 1;

}

unsigned pvl2_students::pvl2_validity_check(unsigned regnum) {

    /* check, if regnum is within bounds first */
    if(regnum < 1 || regnum > 999999) {
        unsigned new_regnum = 0;
        
        cout << "Unzulaessige Eingabe - Matrikelnummer muss sich zwischen 1 " <<
        "und 999999 befinden!" << endl;
        cout << "Bitte erneut eingeben." << endl;

        cin >> new_regnum;
        return pvl2_validity_check(new_regnum);
    }

    /* next check if regnum is already taken */
    else if(pvl2_search_entry(regnum, 0, count)) {
        unsigned new_regnum = 0;
        cout << "Unzulaessige Eingabe - Matrikelnummer ist bereits vergeben." << endl;
        cout << "Bitte erneut eingeben." << endl;

        cin >> new_regnum;
        return pvl2_validity_check(new_regnum);
    }

    /* if regnum is OK, return it to add_entry() */
    return regnum;


}

/* recursive binary search through the array */
unsigned pvl2_students::pvl2_search_entry(unsigned regnum, unsigned start, unsigned end) {
    
    /*first entry exception*/
    if(count == 0) {
        return 0;
    }

    /* no matching value found */
    if(end < start) { return 0; }
    
    unsigned middle = ((start + end) / 2);

    if(registry[middle]->regnum == regnum) {
        return middle;
    }
    else if(registry[middle]->regnum <= regnum) {
        return pvl2_search_entry(regnum, middle + 1, end);
    }
    else if(registry[middle]->regnum >= regnum) {
        return pvl2_search_entry(regnum, start, middle - 1);
    }

}

char* pvl2_students::pvl2_add_courses() {

    char buffer[1000];
    for(int i = 0; i < 1000; i++) {
        buffer[i] = 0;
    }

    cout << "Name des Kurses: ";
    cin.getline(buffer, 1000);
    unsigned stringsize = pvl2_stringsize(buffer);
    char temp[stringsize];
    pvl2_stringcopy(buffer, temp);

    return temp;
}
/* just counts the length of the 0-terminated string in buffer */
unsigned pvl2_students::pvl2_stringsize(char buffer[]) {
    unsigned size = 0;
    
    for(int i = 0; i < 1000; i++) {
        if(buffer[i] != '\0') { size += 1; }
        else { break; }
    }

    return size;
}
/* just copies every single character stored in buffer into new array */
void pvl2_students::pvl2_stringcopy(char buffer[], char temp[]) {
    for(int i = 0; i < 1000; i++) {
        if(buffer[i] == '\0') { break; }
        buffer[i] = temp[i];
    }
}
/* simple recursive function: tests, if regnum-1 - which is previous - is to be found
else returns to itself so long til previous is found 
gets back position of value from search-entry and passes it to add_entry()
*/
unsigned pvl2_students::pvl2_find_prev(unsigned regnum, unsigned previous) {
    
    unsigned position = pvl2_search_entry(previous, 0, regnum);
        
    return previous ? position : pvl2_find_prev(regnum, previous - 1);
}
/* this function reroutes all pointers after an entry, if it is inserted inmidst
other entries. gets the entry and its position, finds out, how many entries are
after (by subtracting position from count) and redirects */ 
void pvl2_students::pvl2_resort(stud* entry, unsigned pos) {
    
    unsigned after = count - pos;
    
    for(unsigned i = 1; i <= after; i++) {
        registry[pos + i] = registry[pos + i + 1];
    }
    
    registry[pos] = entry;
}
/* simple as that: queries the search func for the position
of the entry via its regnum. if sth else than 0 is returned,
deletes the entry and redirects the following ones. if 0 is
returned, the function is sorry, but it can't help you */
void pvl2_students::pvl2_delete_entry(unsigned regnum) {
    
    unsigned pos = pvl2_search_entry(regnum, 0, count);

    if(pos) {
        delete registry[pos];
        for(unsigned i = pos+1; i < count; i++) {
            registry[i-1] = registry[i];
        }
        registry[count] = NULL;
    }

    else {
        cout << "Der angegebene Eintrag konnte nicht gefunden werden." << endl;
        return;
    }

}

bool pvl2_students::pvl2_call_search(unsigned regnum) {
    if(pvl2_search_entry(regnum, 0, count)) {
        return true;
    }
    return false;
}