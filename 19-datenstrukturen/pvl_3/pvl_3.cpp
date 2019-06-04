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
struct stone {
    unsigned l_field = 0;       //left value
    unsigned r_field = 0;       //right value
    bool is_used = false;       //turn to true, if stone is part of circ list
    stone* next = NULL;
};

struct rhead {
    stone* rlist = NULL;
    rhead* next = NULL;
    unsigned rlist_len = 0;
};

void pvl3_input(char* filename, stone* &data_head, unsigned &b_count);
void pvl3_print_list(stone* data_head, unsigned len);
rhead* pvl3_ringlist_master(stone* data_head, unsigned len);
void pvl3_make_ringlist(stone* data_head, rhead* ringlist_head, unsigned len);
void pvl3_print_rlists(rhead* ringlist_head);


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

/* traverses the data list for unused entries (til all booleans in the structs
are true) and delegates found entries towards the ringlist function */
rhead* pvl3_ringlist_master(stone* data_head, unsigned len) {
    
    rhead* llist_head = NULL;
    rhead* llist_prev = NULL;

    for(unsigned i = 0; i < len; i++) {

        if(!data_head->is_used) { 
            
            rhead* temp = new rhead;
            temp->rlist = data_head;
            
            if(i == 0) { llist_head = temp; }           //assign head pointer for first entry
            pvl3_make_ringlist(data_head, temp, len);
            
            temp->rlist_len += 1;
            
            if(llist_prev) { llist_prev->next = temp; } //connect list-heads which point to ringlists
            llist_prev = temp;
            
            data_head = data_head->next;                //traverse 'original' list
        }        
    }

    return llist_head;
}

void pvl3_make_ringlist(stone* data_head, rhead* ringlist_head, unsigned len) {

    //ringlist_head->is_used = true;
    stone* prev = NULL;

    for(unsigned i = 0; i < len; i++) {

        if(!data_head->is_used) {                               //check is prob unnecessary, since each num exists only twice
            if(ringlist_head->rlist->r_field == data_head->l_field 
            || ringlist_head->rlist->r_field == data_head->r_field) {
                
                /* change vals in list entry, if necessary */
                if(ringlist_head->rlist->r_field == data_head->r_field) {
                    unsigned r_tmp = data_head->r_field;
                    data_head->r_field = data_head->l_field;
                    data_head->l_field = r_tmp;
                }
                
                if(prev) { prev->next = ringlist_head->rlist; }
                prev = ringlist_head->rlist;

                ringlist_head->rlist_len += 1;
                ringlist_head->rlist = data_head;
                data_head->is_used = true;
            }
        }
        data_head = data_head->next;
    }
}

void pvl3_print_rlists(rhead* ringlist_head) {

    while(ringlist_head) {
        
        for(unsigned i = 0; i < ringlist_head->rlist_len; i++) {
            cout << "[" << ringlist_head->rlist->l_field << ":" << 
            ringlist_head->rlist->l_field << "]";
        }
        cout << endl;
        ringlist_head = ringlist_head->next;
    }
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

    rhead* rlists_master = pvl3_ringlist_master(data_head, b_count);

    pvl3_print_rlists(rlists_master);

    return 0;
}