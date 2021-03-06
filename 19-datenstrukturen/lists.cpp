//data structures lab 02 May 2019, on lists
//softbobo



#include<iostream>

using namespace std; 

struct node{
    int data = 0;
    node* next = NULL;
};

//task: write a function that prints contents of a list of arbitrary length
//preferably recursive
void writeList(node* head) {
    if(head != NULL) {
        cout << head->data << endl;
        writeList(head->next);
    }
}

//task: insert element at list head
node* insertAtHead(node* head, int val) {
    node* temp = new node;
    temp->next = head;
    temp->data = val;
    head = temp;
    return head;
}

//task: insert element at list end
void insertAtTail(node* head, int val) {
    if(head == NULL) {
        //new node, fill with data 'n stuff
        node* temp = new node;
        temp->next = NULL;
        temp->data = val;
        head = temp;

        return;
    }
    return insertAtTail(head->next, val);
}

//searches for list entry with given value iteratively
node* iterSearch(node* head, int val) {
    while(head->next != NULL) {
        if(head->data == val) { return head; }
    }
    return NULL;
}

//search for list entry recursively
node* recurSearch(node* head, int val) {
    if(head == NULL) { return 0; }
    if(head->data == val) { return head; }
    return recurSearch(head->next, val);
}

//inserts int data into sorted linked list
void insertSorted(node* head, int val) {
        //if(head == NULL) { insertAtTail(head, val); }
        if(val >= head->data) { return insertSorted(head->next, val); }
        else {
            node* temp = new node;
            temp->data = val;
            temp->next = head;
            
        }
}

//write a function to remove the first element of the list
void removeFirst(node* &head) {
    if(head == NULL) { return; }
    
    node* temp = head;
    head = head->next;
    delete temp;
}


//write a functon that removes first item with a given val - recursive
node* removeRecursive(node* head, int val) {
    if (!head) { return NULL; }
    if(head->data == val) {
        node* temp = head->next;
        delete head;
        return temp;
    }
    head->next = removeRecursive(head->next, val);
    return head;
}

//write a functon that removes first item with a given val - iterative
void removeIterative(node* &head, int val) {

}

node* mirrorRecursive(node* head, node* prev) {
    if(!head) { return NULL; }
    
    if(head->next == NULL) { return head; }

    else {
        node* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
        return mirrorRecursive(head, prev);
    }
}

node* mirrorRec(node* head) {
    if(!head) { return NULL; }
    
    if(head->next == NULL) { return head; }

    node* newhead = mirrorRec(head->next);
    head->next->next = head;
    return newhead;
}