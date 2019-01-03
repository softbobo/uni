## C++ Cheats

This cheatsheet is an extension for the docs provided by Andreas Mueller and Ariane Jacobs for the lectures in Informatik I at TU Chemnitz in Winter 2018/19. It is meant to provide information on all C++ syntax and functions used in the lecture and then some. No guarantee for correctness of any kind is given. The document was written by Softbobo.

### Comments

` /* This is a 
Multi-Line comment*/ `

`//This comment ends at the end of the Line`
### Datatypes

Integers: `int`\
Floating Points: `float`\
Character: `char`\
Boolean: `bool`
### Program Structure

End a statement with a semicolon `;` - no matter what!

Prepocessor directives start with a hashtag `#`\
This is used to include files (e.g. headers/libraries) `#include<cmath.h>`

'using' is the keyword to declare a namespace for the whole file: `using namespace std`;

### Variables

Declare an int: `int var;` \
&ensp;&ensp;attributes (stand-alones) for `int` are: `unsigned`,`short`, `long`, and `long long`\
&ensp;&ensp;find the numeric limits of a certain type on your system:/
&ensp;&ensp;```c++
numeric_limits<type>::min(); or max()``` 
&ensp;&ensp;memory used by a certain data type is/
&ensp;&ensp;```c++ sizeof(type);```

Declare multiple floats: `float var_1, var_2, var_3;` \
Declare a char and initialize with a distinct value: `char letter = 'z';`

### Basic I/O

To include the relevant library: `#include<iostream>`\
Output formatted text: `cout << "Write your Text here";`\
Simple user input to a variable (must be declared beforehand): `cin >> var;`\
Linebreak: `endl;`

### Operators

#### Arithemtic Operators
Add var_1 and var_2: `var_1 + var_2;`\
Subtract var_1 and var_2: `var_1 - var_2;`\
Multiply var_1 and var_2: `var_1 * var_2;`\
Divide var_1 and var_2: `var_1 / var_2;`\
Calcutlate the remainder (modulo) of var_1 divided by 2: `var_1 % 2;`\
Overcome operator precedence with brackets: `(var_1 + var_2) * var_3;` - the addition is evaluated before the multiplication\
Short form for evaluating an arithmetic operation and assign is to the variable on the left side of the operator: +=. -=, *=, /=\
Accordingly add var_1 and var_2 and assign the new value to var_1: `var_1 += var_2`\
Increment/decrement var_1 by 1 __after__ adding its value to var_2: `var_2 += var_1++; var_2 += var_1--`\
Increment/decrement var_1 by 1 __before__ adding its value to var_2: `var_2 += ++var_1; var_2 += --var_1`
 
#### Logic Operators

Logic AND: `

#### Relational Operators

#### Bitwise Operators


