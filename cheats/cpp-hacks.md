# C++ Hacks
This node includes code snippets I'll add as I learn. Mostly that's to better grasp the working mode of library functions and workarounds. No guarantee for correctness is given.

## Standard Library

### <string>

### <vector>
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
