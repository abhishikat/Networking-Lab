
#UDP server program
from socket import *

serverName = '127.0.0.1'
serverPort = 12000
serverSocket = socket(AF_INET,SOCK_DGRAM)
serverSocket.bind((serverName,serverPort))
print('The server is ready to receive :')
while True :
    sentence, clientAddress = serverSocket.recvfrom(2048)
    file = open(sentence,'r')
    l = file.read(2048)
    serverSocket.sento(bytes(l,"utf-8"),clientAddress)
    print('Sent back to client')
    file.close()