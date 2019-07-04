import socket

def client():
    clsock = socket.socket(AF_INET, SOCK_STREAM)
    clsock.connect('localhost', 12000)
    msg = raw_input("Bitte Nachricht im Format OPE*VAR*VAR eingeben: ")
    clsock.send(msg)
    msg = clsock.recv(1024)
    print('Das Ergebnis lautet ' + msg)
    clsock.close()