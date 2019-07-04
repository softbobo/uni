import socket

def make_sock():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.bind(('localhost', 8080))
    sock.listen(1)
    while 1:
        conn, addr = sock.accept()
        msg = conn.recv(1024)
        msg = msg.split('*')
        if len(msg) > 2 or len(msg) < 2:
            raise RuntimeError('Falsches Format')
        print('receiving message from IP %d, port %d: %s', addr[0], addr[1], \
            [for item in msg print item])
        result = calc(msg[0], msg[1], msg[2])
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
        raise RuntimeError('Unbekannte Operation!')