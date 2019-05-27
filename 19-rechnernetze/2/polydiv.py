#!usr/bin/env python2
# coding=utf8

# Robert Schulze
# Matrikelnummer: 555625
# Mai 2019

""" Task is:
Write a script that puts out the modulo of a polynomial division of a string
put in from the terminal and the term x**4+x+1 

what the script needs to do:
- take the string from the CLI (what about exceptions)?
- split the input string into a list
- perform division on that list (horner scheme maybe?)
- make output nice
"""

from sys import stdin

""" input function, takes string from CLI, puts it into list """
def polydiv_input():
    line = raw_input("Bitte binäre Zeichenkette eingeben: ")
    line = [line[i:i+1] for i in range(0, len(line), 1)]
    print(line)                                                 # this is for debugging only

""" central function of the bunch, processes the list passed down from 
polydiv_input() with the 10011 crc-vector """
def polydiv_div(list):
    pass

def main():
    """ script launcher """
    pass

if __name__ == "__main__":
    main()