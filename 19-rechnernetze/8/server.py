#!/usr/bin/env python2
# coding=utf8

# Robert Schulze
# Matrikelnummer 555625

""" Taks:
implement a simple server, that takes a basic arithmetic operation and two
numbers at port 8080 an outputs the result pluss proper error handling
"""

import socket


def calc(op, var_1, var_2):
    """ does the calculations """
    if op == "ADD":
        return str(var_1 + var_2)
    elif op == "SUB":
        return str(var_1 - var_2)
    elif op == "MUL":
        return str(var_1 * var_2)
    elif op == "DIV":
        return str(var_1 / var_2)
    else:
        print "Unbekannte Operation!"
        return prompt()
    
def main():
    """ script launcher """
    pass

if __name__ == "__main__":
    main()