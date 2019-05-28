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
""" 

""" input function, takes string from CLI, puts it into list """
def polydiv_input():
    data = raw_input("Bitte Zeichenkette eingeben: ")
    data = [data[i:i+1] for i in range(0, len(data), 1)]
    polydiv_crc(data)

""" central function of the bunch, processes the list passed down from 
polydiv_input() with the 10011 crc-mask, which is poly """
def polydiv_crc(data):
    is_string = isinstance(data, str)
    if not is_string:
        raise Exception("Bitte validen String eingeben!")
    poly = 0x13
    crc = 0

    for c in data:
        crc = crc ^ ord(c)
        for y in range(8):
            if((crc & 0x0001) == 0x0001):
                crc = (crc >> 1) ^ poly
            else:
                crc = crc >> 1

    print("Die Prüfsumme des eingegebenen Strings ist " + str(crc))

def main():
    """ script launcher """
    polydiv_input()
    pass

if __name__ == "__main__":
    main()