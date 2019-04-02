/*implementation for tasks 7.12 and 7.13
bubble-sorty, takes array searches for smallest, swaps it with the front,
decreases array size by 1*/
//softbobo, 190212

#include<iostream>
using namespace std;

int select_smallest(int* arr, int lpos, int rpos);
void select_swap(int* arr, int pos_1, int pos_2);
int* select_sort(int* arr, int size);

int select_smallest(int* arr, int lpos, int rpos) {
    
    int smallest = arr[lpos];
    int pos = lpos;

    for(int i = lpos+1; i <= rpos; i++) {
        if(arr[i] < smallest)
            pos = i;
    }
    return pos;
}

void select_swap(int* arr, int pos_1, int pos_2) {

    int temp = arr[pos_1];
    arr[pos_1] = arr[pos_2];
    arr[pos_2] = temp;
}

int* select_sort(int* arr, int size) {

    int temp;
    for(int i = 0; i < size-1; i++) {
        temp = select_smallest(arr, i, size);
        select_swap(arr, i, temp);
    }
    return arr;
}

int main() {
    int arr_1[] = {1,5,3,876,3, 56, 34,45,2};
    int size_1 = 8;
    select_sort(arr_1, size_1);
    for(int i = 0; i <= size_1; i++) {
        cout << arr_1[i] << " ";
    }
    cout << endl;
    return 0;
}