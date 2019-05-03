/* 
Main function for the whole task block three

softbobo 03 May 2019
*/

using namespace std;

#include"3.h"
#include<iostream>

int main() {
    int data = 5;
    lelem* head = NULL;

    for(int i = 0; i <= data; i++) {
        ll_insert_front(head, data);
    }

    cout << ll_sum(head, data) << endl;

    return 0;
}