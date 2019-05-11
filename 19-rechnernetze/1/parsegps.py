#!/usr/bin/env python2
# Robert Schulze
# Matrikelnummer: 555625
# 09 Mai 2019

"""
next steps:
- fix section distance output for first value (needs to be 0.0)
- fix distance formatting for distance outputs
- write lat and lon to file
"""

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

        if data.index is not 0:
            data.lat_prev = data.lat
            data.lon_prev = data.lon
        data.lat = line[2]
        data.lon = line[3]
        height = line[4]

        distance_section = data.calc_distance(data.lat, data.lon, data.lat_prev, data.lon_prev)
        data.write_to_file(round(distance_section, 3), outfile)

        data.tot_distance += distance_section
        data.write_to_file(round(data.tot_distance, 3), outfile)

        
        data.write_to_file(data.lat, outfile)
        data.write_to_file(data.lon, outfile)
        data.write_to_file(height, outfile)
        


def main():
    """ script launcher """
    logic()
    pass

if __name__ == "__main__":
    main()