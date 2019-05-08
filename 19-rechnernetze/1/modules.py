import math
import datetime as dt
from time import strptime

""" 
takes two time strings, splits those and calcs the difference
gives back string 
pretty ugly, but didn't get my head around timedelta objects
"""
def time_diff(time_prev, time_act):
    time_prev = time_prev.split(':')
    time_act = time_act.split(':')
    hours = int(time_act[0]) - int(time_prev[0])
    mins = int(time_act[1]) - int(time_prev[1])
    secs = int(time_act[2]) - int(time_prev[2])
    return str(hours) + ':' + str(mins) + ':' + str(secs)


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


""" parses a coordinate in minute and second-format into decimal format """
def coord_convert(coord):
    coord = coord.split()
    return (float(coord[0]) * 3600  + float(coord[1]) * 60 + float(coord[2])) / 1000
    

# ouput
def write_to_file(dataset, outfile):
    for item in dataset:
        outfile.write(item)
        outfile.write('\t')
    outfile.write('\n')
