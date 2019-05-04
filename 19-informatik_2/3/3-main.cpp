/* 
Main function for the whole task block three

softbobo 03 May 2019
*/

using namespace std;

#include"3.h"

int main() {
    int data = 5;
    lelem* head = NULL;

    for(int i = 0; i <= data; i++) {
        ll_insert_front(head, data);
    }

    cout << "tot count of all list elements: " << ll_size(head) << endl;
    cout << "percentage of negative values in th list is " << ll_negrelation(head)
    << "%" << endl; 
    cout << "sum of all list elements: " << ll_sum(head, data) << endl;

    ll_remove(head);

    return 0;
}