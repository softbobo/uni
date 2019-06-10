#!usr/bin/env python
# coding=utf8

# Robert Schulze
# Matrikelnummer 555625

""" Task
Write a multiport bridge simulation as a Py script. Args come from 
the CLI of course. Args are: Input port, sender IP and receiver IP.
For simplicity adresses range from 1 to 255, 255 being the broadcast address.
"""

def fill_sat(sat, data_in):
    return

def prompt(sat):
    data_in = []
    while data_in[0] != 'e':
        data_in = raw_input("switch<: ")
        
        """print the whole sat, if input is 'a'"""
        if data_in[0] == 'a':
            for key, values in sat.iteritems():
                print(key + ":" + values)
        
        else:
            for key, values in sat.iteritems():
                """output on all ports if target is broadcast or not yet known"""
                if value != data_in[1] or data_in[2] == '255':
                    print("switch> Ausgabe auf allen Ports")
                    """add adress to sat, if it is not in it yet"""
                    if value != data_in[1]:
                        sat[data_in[0]].append[data_in[1]]
                """print out the port if a value for given address is known"""
                else:
                    print("switch> Ausgabe auf Port " + key)


def main():
    """ script launcher """
    sat = {1:[], 2:[], 3: [], 4:[], 5:[], 6:[]}                       # empty dict represensting all ports
    print("Multiport Bridge Simulation. Steuerung: \
        Pakete verschicken: <Port> <Absenderadresse> <Zieladresse> \
        Ausgabe der Source-Adress-Table: a \
        Programm beenden: e")
    prompt(sat)
    pass

if __name__ == "__main__":
    main()