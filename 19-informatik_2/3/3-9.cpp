/* 
task: write a function, that deletes every list entry,
and sets head to NULL

softbobo 04 May 2019
*/

using namespace std;

#include"3.h"


void ll_remove(lelem* &head) {
    while(head != NULL) { ll_remove_front(head); }
}