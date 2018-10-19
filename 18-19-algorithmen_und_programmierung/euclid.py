#!/usr/env/bin python
#function that checks for GCD with euclidean algorithm

x = int(input('Enter first number here: '))
y = int(input('Enter second number here: '))

def euclidean(x,y):
    if x==y:
        print('The GCD is: ',x)
    elif x>y: 
        return euclidean(x-y,y)
    else:
        return euclidean(y-x,x)

exit(euclidean(x,y))

euclidean(x,y)