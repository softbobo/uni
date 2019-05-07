#!usr/bin/python2
# written by Robert Schulze 25th April 2019

""" First lab assignment for networks. Set as follows:
    - take gps data from a file, it contains date, time, lat, lon and height
    - create output file that contains:
        - index
        - distance to preceding point
        - total distance covered 
        - time difference to preceding point
        - total time
        - pace/speed for last section covered
        - height above sea level
        - lat
        - lon
    - plot a profile graph with gnuplot (distance on x- height on y-axes)
""" 

""" Algo:
    - create vars for time (parse directly into what format?), latitude, longitude,
    and height (2x - for preceding and actual line)
    - open file
    - read in vars line by line and perform ops
    - write line by line to output file
""" 

""" TO DO:
- sanitize input 
"""

import cmath as cm
import os
import datetime as dt


infile = open('data.txt', 'r')
outfile = open('output.plt', 'w')




for line in infile: 
    if not '\t' in line:
        continue
    sline = line.split('\t')
    time = str(sline[1]).split()
    time = time[1]
    lat = sline[2]
    lon = sline[3]
    height = sline[4].replace('\n', '')
    print(time,lat,lon,height)          #only for debugging
