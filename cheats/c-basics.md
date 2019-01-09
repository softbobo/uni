# C Basics Cheat Sheet
Basic declarations and syntax in the C programming language. Feel free to use, though guarantee for correctness is given.

## Basic Data Types and Variables
Data types that have mostly been implemented for as long as C is around. They are pretty generic so you don't even know their exact size on every platform. Different headers from the stdlib give you more precise types, refer to c-hacks.md for those.

`char`: Character
&ensp;&ensp; Characters might be modified with following keywords: `signed`/`unsigned`
`int`: Integer
&ensp;&ensp; Integers might be modified with following keywords: `signed`/`unsigned`, `short`, `long`, `long long`
`bool`: boolean (since C99)
`float`: floating-point number
&ensp;&ensp; Floating points might be modified with following keywords: `double`, `long double` 
`void`: no type really, but used in functions and complex data types to not be nailed down to a single data type (see c-hacks.md); e.g. void-pointers are compatible to all other pointer types

Although C is a statically typed language (when you give data a type, it stays that type for the rest of its lifetime), you can convert data from one type to another (not always - sometimes your compiler will yell at you). This is called _casting_ and done via brackets around the data type you want to cast to before the data/operation you cast on.

## Pointer
Pointer are an essential concept in C - they are variables which store the adress of a memory location (e.g another variable). A pointer is alwas declared with the type of data it is pointing to. Symbol for a pointer is an asterisk '*' that is written inbetween datatype and variable name. To find the correct adress, an ampersand and the variable's name are used. To declare a pointer `ip` that points to the location of `int i`:
```c
int* ip = &i;#
```

Pointers are going to be important especially with data structures/complex data types and functions.

## Static Memory Allocation
Static Memory is mostly allocated via arrays. Arrays have _n_ times the size of the datatype they are declared for, e.g.

```c 
double array[8]
``` 
allocates the size of eight doubles, that are on the stack in one 'row'. This size is immutable. What the array really is, is a pointer to the first element of the array. 

## Dynamic Memory Allocation
Memory allocation during Runtime is done on the heap. You have to manually allocate it and `free()` it afterwards. 

## Complex Datatypes
C's got a few complex datatypes you can use to combine the basic ones (like `int` and `char`) to more meaningful ones. From here, object-oriented programming is not far.

