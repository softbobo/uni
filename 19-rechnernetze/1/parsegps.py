#!/usr/bin/env python2
# Robert Schulze
# Matrikelnummer: 555625
# 09 Mai 2019

# '*' is going to be changed to discrete module names later  
from parsegps_modules import instance

""" as the name says, this is the logic of the script mainly;
it sets a new instance and calls its member functions """
def logic():
    infile = open('data.txt', 'r')
    outfile = open ('output.plt', 'w')

    data = instance()

    for line in infile:
        if '\t' not in line:
            continue
        
        line = line.split('\t')

        data.write_to_file(data.index, outfile)
        data.index += 1

        outfile.write('\n')


def main():
    """ script launcher """
    logic()
    pass

if __name__ == "__main__":
    main()