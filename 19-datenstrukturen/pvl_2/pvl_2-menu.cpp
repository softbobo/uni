/*
Robert Schulze
Matrikelnummer: 555625
May 2019
*/

/* to do:
- change function calls in switch()-statement after rwriting data structure and algo
- write additional function to call search function (doesnt work directly b/c count is private)
*/

/* menu implementation to control function execution for part e) */

using namespace std;

#include"pvl_2-menu.h"
#include"pvl_2.h"

void pvl_2_menu() {

    cout << "Studierendenverwaltung" << endl;
    cout << "==============================" << endl;

    char input = 0;
    while(input != 'E') {

        pvl2_students list;

        cout << "Bitte Eingabe taetigen:" << endl << 
        "A = Anlegen eines neuen Eintrags inkl. bisher belegter Lehrveranstaltungen" << endl <<
        "S = Suchen eines Eintrags" << endl <<
        "L = Loeschen eines Eintrags" << endl <<
        "E = Beenden des Programms" << endl;

        cin >> input;

        unsigned regnum_temp = 0;
        unsigned regnum;

        switch (input) {
        
        case 'A':
            list.pvl2_add_entry();
            break;
        
        case 'S':
            cout << "Bitte gesuchte Matrikelnummer eingeben" << endl;
            cin >> regnum_temp;
            regnum = list.pvl2_validity_check(regnum_temp);  
            if(list.pvl2_search_entry(regnum, 0, list.count)) {
                cout << "Eintrag ist vorhanden."
            } 

            break;
        
        case 'L':
            cout << "Bitte Matrikelnummer des zu loeschenden Eintrags eingeben" << endl;
            cin >> regnum_temp;
            regnum = list.pvl2_validity_check(regnum_temp);   
            list.pvl2_delete_entry(regnum);
            break;

        case 'E':
            cout << "Programm wird beendet" << endl;
            return;
        
        default:
            cout << "unzulaessige Eingabe!" << endl;
            break;
        }
    }

    return;
}

