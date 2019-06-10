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
- introduce checks for max and min ip vals
"""

def search_port(sat, ip):
    for keys, values in sat:
        if ip == values:
            return keys
        else:
            return 0

def prompt(sat):
    data_in = raw_input("switch<: ")
    data_in = data_in.split()

    # check for invalid input
    if len(data_in) != 1 and len(data_in) != 3:
        print("Invalide Eingabe!")
        return prompt(sat)

    if len(data_in) == 3 and data_in[0] < 1 and data_in[0] > 6:
        print("Invalide Eingabe. Portnummer muss sich im Bereich 1-6 befinden!")
        return prompt(sat)
    
    if len(data_in) == 3 and data_in[1] < 0 and data_in[2] < 0 \
        and data_in[1] > 255 and data_in[2] > 255:
        print("Invalide Eingabe. Es können nur IP-Adressen im Bereich von \
            1 bis 255 vergeben werden!")
        return prompt(sat)

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
        # search for the port
        port = search_port(sat, data_in[2])
        # output-ip is already mapped to a port
        if port and data_in[2]:
            print("switch> Ausgabe auf Port " + port)
        # output-ip has no port yet, put out on all ports
        else:
            print("switch> Output auf allen Ports")
        return prompt(sat)

        #for key, values in sat.iteritems():
        #    """output on all ports if target is broadcast or not yet known"""
        #    if values != data_in[1] or data_in[2] == '255':
        #        print("switch> Ausgabe auf allen Ports")
        #        """add adress to sat, if it is not in it yet"""
        #        if values != data_in[1]:
        #            sat[data_in[0]].append(data_in[1])
        #    # print out the port if a values for given address is known
        #    else:

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