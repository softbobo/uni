/* 
implementation of task 1.3: write a function that prints whole array using
pointers exclusively (function signature is given)

Robert Schulze, 03 May 2019
*/

using namespace std;

#include<iostream>

/* recursive implementation, to not forget how to do it */ 
void print(int* array, int len) {
    if(len > 0) {
        cout << *array << " " << len << endl;
        return print(array+1, len - 1);
    }

    return;
}

int main() {
    /* declare the data needed */
    int len = 10;
    int array[len];
    
    /* initialize the array */
    for(int i = 0; i < len; i++) { array[i] = i; }
    
    /* call function */
    print(array, len);

    return 0;
}

