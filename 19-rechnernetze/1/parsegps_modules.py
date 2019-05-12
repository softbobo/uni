# Robert Schulze
# Matrikelnummer: 555625
# 09 Mai 2019

from math import sin, cos, acos, sqrt
import datetime as dt 

class instance():
    index = 0
    lat = "0"
    lon = "0"
    lat_prev = "0"
    lon_prev = "0"
    tot_distance = 0.0
    curr_time = "00:00:00"
    prev_time = "00:00:00"
    tot_time = "00:00:00"
    tot_time_temp = "00:00:00"

    def __init__(self):
        pass

    """
    converts a gps input string in sexagesimal format to decimal degrees
    """
    def sexages_to_dec(self, coord):    
        if coord != '0':
            coord = coord.split()
            return (float(coord[0]) + float(coord[1]) / 60 + float(coord[2]) / 3600)
        else:
            return float(coord)

    """ 
    as the name says, cals the distance between two points on earth, thinking of
    it as an idealized sphere with 40.000km circumference
    now, this implementation and formula varies from the given one (see task), 
    but i just couldn't get my head around this one without implementation
    """ 
    def calc_distance(self, lat, lon, lat_prev, lon_prev):
        lat = self.sexages_to_dec(lat)
        lon = self.sexages_to_dec(lon)
        lat_prev = self.sexages_to_dec(lat_prev)
        lon_prev = self.sexages_to_dec(lon_prev)
        zeta = acos(sin(lat)*sin(lat_prev) + cos(lat)*cos(lat_prev)*cos(lon_prev - lon))
        distance = (zeta/360) * 40000
        return distance


    def calc_timediff(self, time, time_prev):
        format = '%H:%M:%S'
        time = dt.datetime.strptime(time, format)
        time_prev = dt.datetime.strptime(time_prev, format) 
        timediff = time - time_prev
        return str(timediff)

    def timeadd(self, timediff, tot_time_temp):
        format = '%H:%M:%S'
        timediff = dt.datetime.strptime(timediff, format)
        tot_time_temp = dt.datetime.strptime(tot_time_temp, format)
        timediff = dt.timedelta(minutes=timediff.minute, seconds=timediff.second, microseconds=timediff.microsecond)
        tot_time_temp = dt.timedelta(minutes=tot_time_temp.minute, seconds=tot_time_temp.second, microseconds=tot_time_temp.microsecond)
        self.tot_time = tot_time_temp + timediff
        return str(self.tot_time)

    def write_to_file(self, argument, outfile):
        outfile.write(str(argument))
        outfile.write('\t\t')

