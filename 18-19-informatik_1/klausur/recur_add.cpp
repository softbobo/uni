//task 8.11, recursively adds contents of an array
//softbobo, 190212

#include<iostream>
using namespace std;

int recur_add(int sum, int* arr, int index, int max);

int recur_add(int sum, int* arr, int index, int max) {
    sum += arr[index];

    if(index == max) 
        return sum;
    else
        return recur_add(sum, arr, index+1, max);
}

int main() {
    int arr_1[] = {1,6,5,2,8};
    int size_1 = 4;
    
    int sum = recur_add(0, arr_1, 0, size_1);
    cout << sum << endl;
    return 0;
}