/* 
3rd lab assignment for data structures

Robert Schulze
Matrikelnummer: 555625
*/

/*to do:
- make head pointer const?

*/


using namespace std;

#include<iostream>
#include<fstream>


/* data structure representing a single stone */
struct stone{
    unsigned l_field = 0;       //left value
    unsigned r_field = 0;       //right value
    stone* next = NULL;
};

void pvl3_input(char* filename, stone* &head);
void pvl3_print_list(stone* head, unsigned len);


void pvl3_input(char* filename, stone* &head) {

    ifstream infile; 
    infile.open(filename);

    /* error check, if specified file exists and can be opened */
    if(!infile.is_open()) {
        cout << "Spezifizierte Datei kann nicht geöffnet werden. "
        "Bitte Programm erneut starten.";
        exit(1);
    }
    
    /* read in first argument from file, number of blocks */
    char* b_count_tmp = 0;
    unsigned b_count;
    infile >> b_count;
    cout << "debug. read in number of blocks is: " << b_count;

    stone* prev = NULL;
    for(unsigned i = 0; i <= b_count; i++) {
        
        stone* temp = new stone;
        infile >> temp->l_field;
        infile >> temp->r_field;

        /* if this is not the first list entry, route pointer of previous entry
        to this one, then assign current entrie's address*/
        if(prev) { prev->next = temp; }
        prev = temp;

        /* set head to the first list entry */
        if(i == 0) { head = temp; }
    }

    pvl3_print_list(head, b_count);
}

void pvl3_print_list(stone* head, unsigned len) {

    /* could also use pointer arithmetic, i kno*/
    for(unsigned i = 0; i < len; i++) {
        cout << head->l_field << " " << head->r_field << endl;
        head++;
    }

}


int main(int argc, char** argv) {

    /* just one parameter (filename) given? */ 
    if(argc != 2) {
        cout << "Es darf nur ein Argument (der Dateiname) als Parameter übergeben werden."
        "Bitte Programm erneut mit korrekter Eingabe starten!";
        return 1;
    }


    stone* head = NULL;         
    pvl3_input(argv[1], head);



    return 0;
}