/* 
Main function for the whole task block three

softbobo 03 May 2019
*/

/* TO DO:
- fix ll_negrelation: puts out vals > 100%, output also wrong for no negative values at all
- remove formatting in ll_print()
- review ll_sum() function, puts out weird values ('0' for list with -5 -4 -3 -2 -1 0 5)
*/

using namespace std;

#include"3.h"

int main() {
    int data = -5;
    lelem* head = NULL;

    for(int i = 0; i >= data; i--) {
        ll_insert_front(head, i);
    }

    ll_insert_back(head, 5);

    cout << "list elements iterative: ";
    ll_print(head);
    cout << endl;
    
    cout << "list elements recursive: "; 
    ll_print_recursive(head);
    cout << endl;

    cout << "tot count of all list elements: " << ll_size(head) << endl;
    cout << "percentage of negative values in th list is " << 100 * ll_negrelation(head)
    << "%" << endl; 
    cout << "sum of all list elements: " << ll_sum(head, data) << endl;

    ll_remove_data(head, 0);
    cout << "list entries after removal: ";
    ll_print(head);
    cout << endl;

    ll_remove(head);

    return 0;
}