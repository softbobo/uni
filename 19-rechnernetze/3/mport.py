#!/usr/bin/env python2
# coding=utf8

# Robert Schulze
# Matrikelnummer 555625

""" Task
Write a multiport bridge simulation as a Py script. Args come from 
the CLI of course. Args are: Input port, sender IP and receiver IP.
For simplicity adresses range from 1 to 255, 255 being the broadcast address.
"""

""" to do:
- fix multiple value assignment to single key (currently same value is assigned 6 times)
- fix output if port is known (currently does output on all ports in every case)
- fix output in general (everything is output 6 times)
- fix output formatting
"""

def prompt(sat):
    data_in = raw_input("switch<: ")
    data_in = data_in.split()
    # exit-statement
    if data_in[0] == 'e':
        print('Programm wird beendet.')
        exit()
    # print the whole sat, if input is 'a'
    elif data_in[0] == 'a':
        for key, values in sat.iteritems():
            print(key + ':' + ' ' + str(values))
            #print()
        return prompt(sat)
    else:
        for key, values in sat.iteritems():
            """output on all ports if target is broadcast or not yet known"""
            if values != data_in[1] or data_in[2] == '255':
                print("switch> Ausgabe auf allen Ports")
                """add adress to sat, if it is not in it yet"""
                if values != data_in[1]:
                    sat[data_in[0]].append(data_in[1])
            # print out the port if a values for given address is known
            else:
                print("switch> Ausgabe auf Port " + key)
        return prompt(sat)

def main():
    """ script launcher """
    sat = {'1':[], '2':[], '3':[], '4':[], '5':[], '6':[]}                       # empty dict represensting all ports
    print("Multiport Bridge Simulation. Steuerung: \n \
        Pakete verschicken: <Port> <Absenderadresse> <Zieladresse> \n \
        Ausgabe der Source-Adress-Table: a \n \
        Programm beenden: e")
    prompt(sat)
    pass

if __name__ == "__main__":
    main()