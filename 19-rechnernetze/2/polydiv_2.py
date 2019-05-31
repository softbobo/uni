#!/usr/bin/env python2
# coding=utf8

# Robert Schulze
# Matrikelnummer: 555625
# Mai 2019

""" Task is:
Write a script that puts out the rest of a CRC-4 operation on a string
read in from the CLI 

what the script needs to do:
- take the string from the CLI (what about exceptions)?
- split the input string into a list
- perform division on that list (horner scheme maybe?)
- make output nice

2nd version
"""

def inp():
    data = raw_input("Bitte String eingeben: ")
    #data = [ord(x) for x in data]
    #print("debug - data is: ")
    crc(data)

def crc(data):
    poly = 0b10011
    crc_val = 0
    for byte in data:
        crc_val ^= ord(byte) << 8
        for bit in xrange(0,8):
            crc_val <<= 1
    
    print(bin(crc_val))


def main():
    """ script launcher """
    inp()
    pass

if __name__ == "__main__":
    main()

