/* 
3rd lab assignment for data structures

Robert Schulze
Matrikelnummer: 555625
*/

/*to do:
- write deletion function for data list, ringlists, more?
- do a valgrind check
- make output of data list print look like in the task
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
void pvl3_make_ringlist(stone* data_head, rhead* ringlist_head, unsigned len, stone* prev);
void pvl3_print_rlists(rhead* ringlist_head);
void pvl3_cleanup(rhead* rlists_head, stone* data_head);


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

    /* counts the number of list entries already traversed to change len iterator */
    unsigned traversed = 1;

    for(unsigned i = 0; i < len; i++) {

        if(!data_head->is_used) { 
            
            /* first allocate a new entry for the 'master-list' */ 
            rhead* ringlist_head = new rhead;

            /* second make a new stone and copy data of the found one into it */
            stone* temp = new stone;
            temp->l_field = data_head->l_field;
            temp->r_field = data_head->r_field;
            data_head->is_used = true;
            
            /* third: direct the ringlists head to the new entry */
            ringlist_head->rlist = temp;
            ringlist_head->rlist_len += 1;
            
            /* assign head pointer for first entry */
            if(i == 0) { llist_head = ringlist_head; }

            /* fourth: construct ringlist */            
            pvl3_make_ringlist(data_head->next, ringlist_head, len - traversed, temp);
            
            /* fifth: connect list-heads which point to ringlists */
            if(llist_prev) { llist_prev->next = ringlist_head; } 
            llist_prev = ringlist_head;
        }        
        /* traverse list of data entries */
        data_head = data_head->next;
        traversed += 1;                
    }
    return llist_head;
}

void pvl3_make_ringlist(stone* data_head, rhead* ringlist_head, unsigned len, stone* prev) {

    /* flag for complete ringlists */
    bool is_complete = false;

    /*pointer to very first domino, to be able to properly close ringlist */
    stone* begin = ringlist_head->rlist;

    while(!is_complete) {
        
        for(unsigned i = 0; i < len; i++) {

            if(!data_head->is_used) {                               //check is prob unnecessary, since each num exists only twice

                /* first: check, if either the right or left entries match 
                to the right entry of current domino */
                if(ringlist_head->rlist->r_field == data_head->l_field 
                || ringlist_head->rlist->r_field == data_head->r_field) {

                    /* second: make a new entry, copy data, and change vals 
                    if necessary */
                    stone* temp = new stone;
                    if(ringlist_head->rlist->r_field == data_head->r_field) {
                        temp->r_field = data_head->l_field;
                        temp->l_field = data_head->r_field;
                    }
                    else {
                        temp->r_field = data_head->r_field;
                        temp->l_field = data_head->l_field;
                    }
                    data_head->is_used = true;

                    /* third: connect list entries */
                    prev->next = temp;
                    prev = temp;
                    ringlist_head->rlist_len += 1;
                    ringlist_head->rlist = ringlist_head->rlist->next;

                    /* fourth: if last value in circle matches first, close the 
                    circle and set completion flag */
                    if(temp->r_field == begin->l_field) {
                        temp->next = begin;
                        is_complete = true;
                        break;
                    }
                }
            }
            data_head = data_head->next;
        }
    }
}


void pvl3_print_rlists(rhead* ringlist_head) {

    while(ringlist_head) {
        
        for(unsigned i = 0; i < ringlist_head->rlist_len; i++) {
            cout << "[" << ringlist_head->rlist->l_field << ":" << 
            ringlist_head->rlist->r_field << "]";
            ringlist_head->rlist = ringlist_head->rlist->next;
        }
        cout << endl;
        ringlist_head = ringlist_head->next;
    }
}

/* like a destructor, frees all allocated memory */ 
void pvl3_cleanup(rhead* rlists_head, stone* data_head) {

    /* first: free the ringlists */
    while(rlists_head) {
        
        /* save the val at the beginning of the list, so u kno when to stahp! */
        unsigned stop = rlists_head->rlist->l_field;

        while(rlists_head->rlist) {

            /* first check, is last entry of circle is reached */
            if(rlists_head->rlist->r_field == stop) {
                delete rlists_head->rlist;
                break; 
            }

            /* if end is not reached store next entry temporary and delete 
            current */
            stone* next = rlists_head->rlist->next;
            delete rlists_head->rlist;
            rlists_head->rlist = next;
        }

        /* if entries of cirle are deleted, delete its head */
        rhead* prev = rlists_head;
        rlists_head = rlists_head->next;
        delete prev;
    }

    /* second: free the data list */
    while(data_head) {
        stone* prev = data_head;
        data_head = data_head->next;
        delete prev;
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

    rhead* rlists_head = pvl3_ringlist_master(data_head, b_count);

    pvl3_print_rlists(rlists_head);

    pvl3_cleanup(rlists_head, data_head);

    return 0;
}