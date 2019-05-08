import math
import datetime as dt

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
def write_to_file(dataset, outfile):
    for item in dataset:
        outfile.write(item)
        outfile.write('\t')
    outfile.write('\n')
