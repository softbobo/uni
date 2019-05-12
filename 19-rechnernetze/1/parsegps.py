#!/usr/bin/env python2
# Robert Schulze
# Matrikelnummer: 555625
# 09 Mai 2019

""" BEMERKUNGEN:
Diese Lösung hat drei Schwachstellen:
1. Die Formatierung des Outputs (die Einheitlichkeit der Tabelle) - hierauf habe
 ich keine Energie vermwendet, da die Datei sich auch so problemlos für Gnuplot
 verwenden laesst.
2. Die Code-Qualitaet: Hier liessen sich sicher die meisten Fortschritte machen,
 indem man weiter abstrahiert. 
3. Die berechnete Distanz - diese is wesentlich kürzer als die in der Aufgaben-
 stellung berechnete. Das haengt mit der anderen verwendeten Formel und vermut-
 lich auch Ungenauigkeiten in der Fliesskommaarithmetik zusammen 
"""

"""
next steps:
- fix indentation for all lines after line 1
- write documentation
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

        data.lat_prev = data.lat
        data.lon_prev = data.lon
        data.lat = line[2]
        data.lon = line[3]
        height = line[4].replace("\n", "")

        if data.lat_prev is "0":
            distance_section = 0.0
        else: 
            distance_section = data.calc_distance(data.lat, data.lon, data.lat_prev, data.lon_prev)
        data.write_to_file(round(distance_section, 1), outfile)
       

        data.tot_distance += (distance_section / 1000)
        data.write_to_file(round(data.tot_distance, 3), outfile)

        data.prev_time = data.curr_time
        data.curr_time = line[1].split()
        data.curr_time = data.curr_time[1]

        if data.prev_time == "00:00:00":
            timediff = "00:00:00"
            data.write_to_file(timediff, outfile)
        else:
            timediff = data.calc_timediff(data.curr_time, data.prev_time)
            data.write_to_file(timediff, outfile)

        data.write_to_file(data.timeadd(timediff, data.tot_time), outfile)
        
        data.write_to_file(round(data.speed(timediff, distance_section), 3), outfile)

        data.write_to_file(height, outfile)
        data.write_to_file(data.lat, outfile)
        data.write_to_file(data.lon, outfile)
        data.write_to_file("\n", outfile)
        


def main():
    """ script launcher """
    logic()
    pass

if __name__ == "__main__":
    main()