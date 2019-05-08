#!usr/bin/python2
# written by Robert Schulze 25th April 2019

""" First lab assignment for networks. Set as follows:
    - take gps data from a file, it contains date, time, lat, lon and height_act
    - create output file that contains:
        - index
        - distance to preceding point
        - total distance covered 
        - time difference to preceding point
        - total time
        - pace/speed for last section covered
        - height_act above sea level
        - lat
        - lon
    - plot a profile graph with gnuplot (distance on x- height_act on y-axes)
""" 

""" Algo:
    - create vars for time (parse directly into what format?), latitude, longitude,
    and height_act (2x - for preceding and actual line)
    - open file
    - read in vars line by line and perform ops
    - write line by line to output file
""" 

""" TO DO:
- conversion to decimal degrees in dist_diff
- make variables for main for loop global
"""

import math
import datetime as dt

#basic file i/o
infile = open('data.txt', 'r')
outfile = open('output.plt', 'w')

#get input
index = 0

#calculations
def time_diff(time_prev, time_act):
    return dt.timedelta(time_prev, time_act)

# this function is ugly and surely can be optimized
# taken from the task however
def dist_diff(lat_prev, lon_prev, lat_act, lon_act):
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
tot_distance = 0
tot_time = "00:00:00"
lat_act = 0
lon_act = 0
lat_prev = 0
lon_prev = 0

# this is the whole logic in a single for loop - urgh
for line in infile: 
    
    # empty list to fill with data and pass to write_to_file in the end
    dataset = []

    # leave out lines without actual data
    if not '\t' in line:
        continue
    
    # write index to dataset 
    dataset.append(index)
    
    # parse input to list
    line = line.split('\t')

    
    # same here: first check for the previous value,
    # then parse input of current line,
    # calculate difference in distance,
    # write to dataset(),
    # add to total dist covered and write to dataset(), too
    if lat_act != 0 and lon_act != 0:
        lat_prev = lat_act
        lon_prev = lon_act
    lat_act = line[2]
    lon_act = line[3]
    dist_delta = dist_diff(lat_prev, lon_prev, lat_act, lon_act)
    tot_distance += dist_delta
    dataset.append(dist_delta)
    dataset.append(tot_distance)

    # check first, if we already have a time value (i.e. not first line of input)
    # then find actual time in current line
    # call time_diff and write return val to dataset
    if time_act != 0:
        time_prev = time_act
    time_act = str(line[1]).split()
    time_act = time_act[1]
    dataset.append(time_diff(time_act, time_prev))



    # height is ez
    height = line[4].replace('\n', '')
    dataset.append(height)
    

    write_to_file(dataset)

    # increment index right away for the next line
    index += 1




