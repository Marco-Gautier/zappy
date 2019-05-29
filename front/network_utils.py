import select

def recv(sockfd):
    fds = select.select([sockfd], [], [], 0.1)
    if len(fds[0]) != 0 and fds[0][0] == sockfd:
        return sockfd.recv(1024).decode()
    else:
        return None

def send(sockfd, message):
    message += '\n'
    sockfd.send(message.encode())

""" Connect client to GRAPHIC team """
def connect_client(sockfd, args):
    sockfd.connect((args.machine, args.port))
    if recv(sockfd) != "Welcome!\n":
        print("server should have responded 'Welcome\\n'")
        exit(1)
    send(sockfd, "GRAPHIC")
