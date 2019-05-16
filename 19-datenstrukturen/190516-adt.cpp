//data structures lab 16th may 2019
//softbobo

/* implementation of a doubly linkes list as an ADT */

using namespace std;

#include<iostream>

class List {

    struct node {
        node* next;
        node* prev;
        int data;
    };
    node* head;
    node* tail;

    public:
        
        List();                             //constructor
        ~List();                            //destructor
        void print_list();
        void insert_node(int value);
        void remove_node(int value);
        bool node_exists(int value);
        int count();
};

List::List() {
    head = NULL;
    tail = NULL;
}

List::~List() {
    if(head) {
        while(head->next) {
            head = head->next;
            delete head->prev;
        }
        delete head;
    }
}

void List::print_list() {
        node* temp = head;
        while(temp){
            cout << temp->data << endl;
            temp = temp->next;
    }
}

void List::insert_node(int value) {
    node* temp = new node;
    temp->data = value;
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void List::remove_node(int value) {
    node* temp = head;

    while(temp) {
        if(temp->data = value) {
            if(!temp->prev) {
                temp->next->prev = NULL;
                head = temp->next;
                delete temp;
            }
            else if(!temp->next) {
                temp->prev->next = NULL;
                tail = temp->prev;
                delete temp;
            }
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
        }
    }
}

bool List::node_exists(int value) {
    if(head) {
        node* temp = head;
        while(temp) {
            if(temp->data) { return true; }
        }
    }
    return false;
}

int List::count() {
    int count = 0;
    if(head) {
        node* temp = head;
        while(temp) {
            count += 1;
            temp = temp->next;
        }
    }

    return count;
}

int main() {
    List test;

    test.insert_node(42);

    test.print_list();


    return 0;
}