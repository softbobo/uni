#!/usr/bin/env python2
# coding=utf8

# Robert Schulze
# Matrikelnummer 555625

import socket

HOST = "127.0.0.1"
PORT = 8080

def server():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.bind((HOST, PORT))
    sock.listen(1)
    while True:
        conn, addr = sock.accept()
        msg = conn.recv(1024)
        msg = msg.split('*')
        if len(msg) > 3 or len(msg) < 3:
            conn.send(result)
            conn.close()
            sock.close()
            raise RuntimeError('Falsches Format')
        print('receiving message from IP %d, port %d: %s', addr[0], addr[1], \
            [item for item in msg])
        result = calc(msg[0], float(msg[1]), float(msg[2]))
        conn.send(result)
        conn.close()
    sock.close()

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
        return "Unbekannte Operation!"

if __name__ == "__main__":
    server()
    pass