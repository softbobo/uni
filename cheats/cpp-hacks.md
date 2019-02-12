# C++ Hacks
This node includes code snippets I'll add as I learn. Mostly that's to better grasp the working mode of library functions and workarounds. No guarantee for correctness is given.

## Standard Library

### string

### vector
A vector is an automatically allocated array. It facilitates its use but does have a little overhead (compared to C-arrays or `std::array`). It has a memory-optimized version for bools, where each element takes 1 bit only. Time complexity is constant for random access and adding/removing elements at the arrays end and linear to the arrays end for adding/removing stuff for any other position in the array.

## Dynamic Memory Allocation
### Dynamically allocate a 2D Array
There are several ways to dynamically allocate 2D arrays in C++. Here is one without using any library functions: 
```c++
//the data structure we want to derive an array from
struct example{
    float val_x;
    float val_y;
};

//you need to derive the array dimensions from somewhere, in this example, we simply set them
int rows = 2;
int cols = 4;

//for an struct array, first create a pointer to that struct type
example* array = new example;

//allocate the rows (1st dimension) first, then allocate memory for each row (2nd dimension)
//like a matrix where you write the first column first and from there all the rows
for(int i = 0; i < rows; i++) {
    example[i] = new example[cols];
}

//delete the data from the heap when you don't need it anymore

for(int i = 0; i < rows; i++) {
    delete [] example[i];
}
delete [] example;
```
this info is mostly from here https://gsamaras.wordpress.com/code/dynamic-2d-array-in-c/ 
and https://stackoverflow.com/questions/983244/is-this-deallocation-correct/983259#983259

## Sorting
### sort()
This is the sorting algorithm of the C++ Standard Library. Its first two args are simply pointers to the beginning and end of the sorting. The third one is a little trickier. In this case, it takes a pointer to a boolean function which defines the parameter to sort after. This function takes two adresses (the two args to compare) and returns true, wheter one of those is greater than the other.
```C++
#include<algorithm>                     //has the sort() algo

using namespace std;

struct example {
    int num;
    char name[20];
    bool is_it;
}

bool sort_by_number(const example &a, const example &b) {
    return a.num < b.num;
    //returns TRUE if the pair is already sorted in ascending order; else returns false and changes those
}

int main() {
    example* ex_list = new example[10];
    // enter list entries
    sort(list, list+10, sort_by_number);
    // print out list entries sorted by number
    // delete, return etc
}
```
The info on sort() is derived from here: http://www.cplusplus.com/articles/NhA0RXSz/

### Simple Bubblesort
A simple Bubblesort implementation in C++ might look like this:
``` C++
/* In Bubblesort you have to traverse the array n-1 times, where n is equal to the count of elements of the array. Also, the greatest elemtent always goes to the back in each iteration, therefore the search area decreases by 1 with each interation */
int* bsort_arr(int* arr, int size) {
    for(int i = size, i > 0; i--) {
        for(int j = 0, j < i, j++) {
            if(arr[j] > arr[j+1])
                swap(arr, i, i+1);
        }
    }
}
```