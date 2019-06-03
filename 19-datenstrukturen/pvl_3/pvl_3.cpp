/* 
3rd lab assignment for data structures

Robert Schulze
Matrikelnummer: 555625
*/

/*to do:

*/


using namespace std;

#include<iostream>
#include<fstream>


/* data structure representing a single stone */
struct stone{
    unsigned l_field = 0;       //left value
    unsigned r_field = 0;       //right value
    bool is_used = false;       //turn to true, if stone is part of circ list
    stone* next = NULL;
};

void pvl3_input(char* filename, stone* &data_head, unsigned &b_count);
void pvl3_print_list(stone* data_head, unsigned len);
void pvl3_ringlist_master(stone* data_head, unsigned len);

/* reads in data from file and populates singly linked data list */
void pvl3_input(char* filename, stone* &data_head, unsigned &b_count) {

    ifstream infile; 
    infile.open(filename);

    /* error check, if specified file exists and can be opened */
    if(!infile.is_open()) {
        cout << "Spezifizierte Datei kann nicht geöffnet werden. "
        "Bitte Programm erneut starten.";
        exit(1);
    }
    
    /* read in first argument from file, number of blocks */
    infile >> b_count;
    cout << "debug. read in number of blocks is: " << b_count << endl;

    stone* prev = NULL;
    for(unsigned i = 0; i < b_count; i++) {
        
        stone* temp = new stone;
        infile >> temp->l_field;
        infile >> temp->r_field;

        /* if this is not the first list entry, route pointer of previous entry
        to this one, then assign current entrie's address*/
        if(prev) { prev->next = temp; }
        prev = temp;

        /* set data_head to the first list entry */
        if(i == 0) { data_head = temp; }
    }

    pvl3_print_list(data_head, b_count);
}
/* just prints the list of input data */
void pvl3_print_list(stone* data_head, unsigned len) {

    for(unsigned i = 0; i < len; i++) {
        cout << data_head->l_field << " " << data_head->r_field << endl;
        data_head = data_head->next;
    }
}

/* traverses the data listfor unused entries (til all booleans in the structs
are true) and delegates found entries towards the ringlist function */
void pvl3_ringlist_master(stone* data_head, unsigned len) {

}


int main(int argc, char** argv) {

    /* just one parameter (filename) given? */ 
    if(argc != 2) {
        cout << "Es darf nur ein Argument (der Dateiname) als Parameter übergeben werden."
        "Bitte Programm erneut mit korrekter Eingabe starten!";
        return 1;
    }

    unsigned b_count = 0;
    stone* data_head = NULL;         
    pvl3_input(argv[1], data_head, b_count);

    return 0;
}