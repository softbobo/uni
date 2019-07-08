#!/usr/bin/env python2
# coding=utf8

# Robert Schulze
# Matrikelnummer 555625s

import socket

def client():
    clsock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    clsock.connect(("localhost", 8080))
    msg = raw_input("Bitte Nachricht im Format OPE*VAR*VAR eingeben: ")
    clsock.send(msg)
    msg = clsock.recv(1024)
    print("Das Ergebnis lautet " + msg)
    clsock.close()

if __name__ == "__main__":
    client()
    pass