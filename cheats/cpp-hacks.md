# C++ Hacks
This node includes code snippets I'll add as I learn. Mostly that's to better grasp the working mode of library functions and workarounds. No guarantee for correctness is given.

## Basic Algos 
### Swap
``` C++
void swap(int* arr, int lpos, int rpos) {
    /*takes the array, left and right operand to swap and swaps them*/
    int temp = arr[lpos];
    arr[lpos] = arr[rpos];
    arr[rpos] = temp; 

    /*also works with void swap(int* lhs, int* rhs), then you gotta pass the adresses
    (e.g. &rhs) in the calling function*/
}
```

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

## Recursion
### Ackermann Function
``` C++
//don't try this for m > 3 or n > 3 on a conventional machine
long long ack(unsigned m, unsigned n) {
    if(m == 0) return n + 1;
    else if(n == 0 && m > 0) return ack(m-1, 1);
    else return ack(m-1, ack(m, n-1));
}
```
### Euclidean Algorithm 
``` C++
//returns greatest common divisor for two Integers, simple implementation
//works in C, too
int euclid(int a, int b) {
    if(a == 0) return b;                    //simple error handling here
    if(b == 0) return a;

    if(a == b) return a;                    //recursion end

    if(a > b) return euclid(a - b, b);
    else return euclid(a, b-a);
}
```

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
/* In Bubblesort you have to traverse the array n-1 times, where n is equal to the count of elements of the array.
Also, the greatest elemtent always goes to the back in each iteration, therefore the search area decreases by 1 
with each interation */
int* bsort_arr(int* arr, int size) {
    for(int i = size, i > 0; i--) {
        for(int j = 0, j < i, j++) {
            if(arr[j] > arr[j+1])
                swap(arr, i, i+1);
        }
    }
}
```
## I/O
### Basic Text I/O
`iostream` is the header you want
pay attention to the directions the filestream operators are pointing to!
``` C++
// print text (ASCII!) to stdout
cout << "Print text!";
// let the user input sth, say the value of an int variable
int var;
cin >> var;
// make a newline, flush the ourstream at the same time
cout << "flushit" << endl; 
```

### Formatting your Output
`iomanip` has functions dedicated to make your output prettier 
``` C++
// change output field width
cout << setw(5) << "out" << endl;
// set floating-point precision (number of decimals after the point)
cout << setprecision(3) << 3.7862 / 0.0023;
// set the base for an integer that is is to be converted to (e.g. binary, octal)
cout << setbase(2) << 24;

```

The relevant library is `fstream` which inherits all methods and classes from `iostream`.
### Copying a File to Another File
``` C++
#include<fstream>

using namespace std;

int main() {
    //open input for reading and output for writing
    ifstream input("iname.txt");
    ofstream output("oname.txt");
    
    //check, if opening was successful (beter do for both files seperately)
    if(!input.is_open() || !output.is_open()) {
        cout << "Cannot open input or output file" << endl;
        exit(1);
    }

    char c;

    //copy char by char
    while(input.get(c)) {
        output.put(c)
    }

    //after closing both streams get flushed and can be used anew
    input.close();
    output.close();

    return 0;
}
```