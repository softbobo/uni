//little program to implement a bubblesort algo w/o lib functions in cpp
//softbobo 190212

#include<iostream>

using namespace std;

int* try_bsort(int* arr, int size);
void try_swap(int* arr, int lpos, int rpos);
void try_print(int* arr);

int* try_bsort(int* arr, int size) {
    /*compares every pos in the array n-1 times (to be sure that the array is
     sorted, that's how bubblesort works), gives them to swap() if necessary*/
    for(int i = size; i > 0; i--) {
        /*starting in reverse order, because the biggest element always goes
        to the back first time*/
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[j+1]) {
                try_swap(arr, j, j+1);
            }
        }
    }
    return arr;
}

void try_swap(int* arr, int lpos, int rpos) {
    /*takes the array, left and right operand to swap and swaps them*/
    int temp = arr[lpos];
    arr[lpos] = arr[rpos];
    arr[rpos] = temp; 
}

void try_print(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr_1[] = {1,5,7,3,86,23,4,5,678,32,8524,3,5,6,0};
    int size_1 = 15;
    try_bsort(arr_1, size_1);
    try_print(arr_1, size_1);
    
    return 0;
}