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
- wirte the calculations section
- organize into application logic
"""

import math
import datetime as dt

#basic file i/o
infile = open('data.txt', 'r')
outfile = open('output.plt', 'w')

#get input
index = 0

#calculations
def timediff(time_prev, time_act):
    return dt.timedelta(time_prev, time_act)

# this function is ugly and surely can be optimized
# taken from the task however
def distdiff(lat_prev, lon_prev, lat_act, lon_act):
    lat_prev = math.radians(lat_prev)
    lon_prev = math.radians(lon_prev)
    lat_act = math.radians(lat_act)
    lon_act = math.radians(lon_act)
    latdiff = lat_act - lat_prev
    londiff = lon_act - lon_prev
    a = math.sin(latdiff/2.0)**2 + math.cos(lat_prev) * math.cos(lat_act) * math.sin(londiff/2.0)**2
    b = 2.0 * math.asin(min(1, math.sqrt(a)))
    return 6396.0 * b 
    

# ouput
def write_to_file(dataset):
    for item in dataset:
        outfile.write(item)
        outfile.write('\t')
    outfile.write('\n')

index = 0

# this is the whole logic in a single for loop - urgh
for line in infile: 
    
    # empty list to fill with data and pass to write_to_file in the end
    dataset = []

    # leave out lines without actual data
    if not '\t' in line:
        continue
    
    # write index to dataset 
    dataset.append(index)
    
    # parse input
    sline = line.split('\t')
    time = str(sline[1]).split()
    time = time[1]
    lat = sline[2]
    lon = sline[3]
    height = sline[4].replace('\n', '')
    dataset = [time, lat, lon, height]
    write_to_file(dataset, index)

    # increment index right away for the next line
    index += 1




