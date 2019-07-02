#!/usr/bin/env python2
# coding=utf8

# Robert Schulze
# Matrikelnummer 555625

""" Taks:
implement a simple server, that takes a basic arithmetic operation and two
numbers at port 8080 an outputs the result plus proper error handling
"""

""" 
Hier werden Stream-Sockets genutzt, da die Reihenfolge und Vollständigkeit 
der Daten für eine zuverlässige Berechnung des Ergebisses unabdingbar sind.
Die Verbingsungsgeschwindigkeit ist jedoch weniger ausschlaggebend, da hier
nur erwartbar wenige Daten übermittelt werden.
"""

import server, client

def calc(op, var_1, var_2):
    """ does the calculations """
    if op == "ADD":
        return str(var_1 + var_2)
    elif op == "SUB":
        return str(var_1 - var_2)
    elif op == "MUL":
        return str(var_1 * var_2)
    elif op == "DIV":
        return str(var_1 / var_2)
    else:
        print "Unbekannte Operation!"
        return client()
    
def main():
    """ script launcher """
    pass

if __name__ == "__main__":
    main()