
This cheatsheet is an extension for the docs provided by Andreas Mueller and Ariane Jacobs for the lectures in Informatik I at TU Chemnitz in Winter 2018/19. It is meant to provide information on all C++ syntax and functions used in the lecture and then some. No guarantee for correctness of any kind is given. The document was written by Softbobo.

### Escape
First things first: The escape character is a BACKSLASH `\`!
### Comments

` /* This is a 
Multi-Line comment*/ `

`//This comment ends at the end of the Line`
### Basic Data Types

Integers: `int`\
Floating Points: `float`\
Character: `char`\
Boolean: `bool`
### Program Structure

End a statement with a semicolon `;` - no matter what!

Prepocessor directives start with a hashtag `#`\
This is used to include files (e.g. headers/libraries) `#include<cmath>`

'using' is the keyword to declare a namespace for the whole file: `using namespace std`;

### Variables
Declare an int: `int var;` \
&ensp;&ensp;attributes (stand-alones) for `int` are: `unsigned`,`short`, `long`, and `long long`\
&ensp;&ensp;find the numeric limits of a certain type on your system (library: <limits>):/
&ensp;&ensp;```c++ #include<limits>
&ensp;&ensp; numeric_limits<type>::min(); or max()``` 
&ensp;&ensp;memory used by a certain data type is/
&ensp;&ensp;```c++ sizeof(type);``` (outputs number of bytes)

Declare multiple floats: `float var_1, var_2, var_3;` \
&ensp;&ensp; attributes (stand-alones) for floats are: `double` and `long double`\ 
&ensp;&ensp; may be also written as suffixes: 'f' or 'F' for `float` and 'l' or 'L' for `long double` 
Declare a char and initialize with a distinct value: `char letter = 'z';`

### Basic I/O
The relevant library: `iostream`\
Output formatted text: `cout << "Write your Text here";`\
Simple user input to a variable (must be declared beforehand): `cin >> var;`\
Linebreak: `endl;`

### Conditionals
Conditionals take an expression and evaluate if it's true or false. 

#### If/Else
'If' doesn't always need an 'Else' but vice-versa 'Else' can't exist without an 'If'.
The condition to evaluate is always in brackets '()'. If there is more than one condition
you concatenate those with logic operators. If there is more than one statement to execute
(code to execute after an 'If' or 'Else' if it evaltuates to true) it needs to be in curly 
braces. Syntax:

```c++
if(var_1 > var_2 && var_2 > var_3)
{
    cout << "var_1 is the biggest value" << endl;
    cout << "I will add var_3 to var_2" << endl;
    var_2 += var_3; 
}

else if(var_2 < var_3)
    cout << "var_3 is bigger than var_2" << endl;

else
    cout << "var_2 is the biggest value" << endl;
```

Be careful to separate the conditions if you only want one condition to execute. You can also have 
fallthroughs with `If` and `Else` when multiple condition evaluate to TRUE. If you are not able
or too lazy to fully think your conditions through (so only one is TRUE at any given time), you may use
the `break` statement tell the compiler it shall stop evaluating the scope the program is currently in
and continue executing the scope above.

```c++
if(var_1 > var_2)
{
    cout << "var_1 is greater var_2!" << endl;
    break;
}
else
    cout << "whatever..." << endl;
```
### Operators

#### Arithemtic Operators
Add var_1 and var_2: `var_1 + var_2;`\
Subtract var_1 and var_2: `var_1 - var_2;`\
Multiply var_1 and var_2: `var_1 * var_2;`\
Divide var_1 and var_2: `var_1 / var_2;`\
Calcutlate the remainder (modulo) of var_1 divided by 2: `var_1 % 2;`\
&ensp;&ensp; Remember: Do not use modulo on floats!
Overcome operator precedence with brackets: `(var_1 + var_2) * var_3;` - the addition is evaluated before the multiplication\
Short form for evaluating an arithmetic operation and assign is to the variable on the left side of the operator: +=. -=, *=, /=\
Accordingly add var_1 and var_2 and assign the new value to var_1: `var_1 += var_2`\
Increment/decrement var_1 by 1 __after__ adding its value to var_2: `var_2 += var_1++; var_2 += var_1--`\
Increment/decrement var_1 by 1 __before__ adding its value to var_2: `var_2 += ++var_1; var_2 += --var_1`
 
#### Logic Operators


#### Relational Operators

Is var_1 greater than var_2: `var_1 > var_2`\
Is var_1 smaller than var_2: `var_1 < var_2`\
Is var_1 equal to var_2: `var_1 == var_2`\
Is var_1 smaller or equal to var_2: `var_1 <= var_2`\
Is var_1 greater or equal to var_2: `var_1 >= var_2`\
Is var_1 unequal to var_2: `var_1 != var_2`\

#### Bitwise Operators

### Namespaces


