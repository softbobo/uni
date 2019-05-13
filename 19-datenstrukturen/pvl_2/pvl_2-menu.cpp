/*
Robert Schulze
Matrikelnummer: 555625
May 2019
*/

/* to do:
- add validity check for regnums
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

        switch (input) {
        
        case 'A':
            list.pvl2_add_student();
            break;
        
        case 'S':
            unsigned regnum;
            cout << "Bitte gesuchte Matrikelnummer eingeben" << endl;
            cin >> regnum;
            list.pvl2_regnum_is_valid(regnum, input);                    
            break;
        
        case 'L':
            unsigned regnum;
            cout << "Bitte Matrikelnummer des zu loeschenden Eintrags eingeben" << endl;
            cin >> regnum;
            list.pvl2_regnum_is_valid(regnum, input);
            break;
        
        default:
            cout << "unzulaessige Eingabe!" << endl;
            break;
        }
    }

    return;
}

