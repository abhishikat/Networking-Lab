
#UDP client program
from socket import *

serverName = '127.0.0.1'
serverPort = 12000
clientSocket = socket(AF_INET,SOCK_DGRAM)
sentence = input('Enter file name : ')
clientSocket.sento(bytes(sentence,"utf-8"),(serverName,serverPort))
filecontents, serverAddress = clientSocket.recvfrom(2048)
print('From Server', filecontents)
file.close()