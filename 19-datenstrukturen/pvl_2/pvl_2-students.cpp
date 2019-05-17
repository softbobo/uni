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

    count = 0;
}                          

void pvl2_students::pvl2_add_entry() {
    stud* temp = new stud;
        
    /* first copy regnum to new entry */
    unsigned regnum = 0;
    cout << "Bitte Matrikelnummer des Studierenden eingeben: ";
    cin >> regnum;
    temp->regnum = pvl2_validity_check(regnum);

    /* next is adding courses to the new entry*/
    cout << "Bitte den ersten Kurs in die Datenbank eingeben" << endl;
    pvl2_add_courses(temp);

    /* now insert the entry sorted */


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
struct stud* pvl2_students::pvl2_search_entry(unsigned regnum, unsigned start, unsigned end) {
    
    /* no matching value found */
    if(end < start) { return NULL; }
    
    unsigned middle = ((start + end) / 2);

    if(registry[middle]->regnum == regnum) {
        return registry[middle];
    }
    else if(registry[middle]->regnum <= regnum) {
        return pvl2_search_entry(regnum, middle + 1, end);
    }
    else if(registry[middle]->regnum >= regnum) {
        return pvl2_search_entry(regnum, start, middle - 1);
    }

}

void pvl2_students::pvl2_add_courses(stud* entry) {
    char buffer[1000];

    for(int i = 0; i < 30; i++) {
        cin.getline(buffer, 1000);
        unsigned stringsize = pvl2_stringsize(buffer);
        char temp[stringsize];
        pvl2_stringcopy(buffer, temp);

        entry->courses[i] = temp;

        char answer = 0;
        cout << "Weiteren Kurs eingeben? [Y/N]" << endl;
        cin >> answer;
        
        if(answer == 'Y') { continue; }
        else if (answer == 'N') { break; }
        else {
            cout << "Unklare Eingabe, Kurs-Eingabe wird abgebrochen!" << endl;
            break;
        }
    }
}
/* just counts the length of the 0-terminated string in buffer */
unsigned pvl2_students::pvl2_stringsize(char buffer[]) {
    unsigned count = 0;
    
    for(int i = 0; i < 1000; i++) {
        while(buffer[i] != '\0') { count += 1; } 
    }

    return count;
}
/* just copies every single character stored in buffer into new array */
void pvl2_students::pvl2_stringcopy(char buffer[], char temp[]) {
    for(int i = 0; i < 1000; i++) {
        if(buffer[i] == '\0') { break; }
        buffer[i] = temp[i];
    }
}