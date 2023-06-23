import socket

host = socket.gethostbyname("localhost")
port = 55001
data = "NULL"

with (socket.socket(socket.AF_INET, socket.SOCK_STREAM)) as s:
    s.connect((host, port))
    
    sendData = input("Message to send to server: ")
    s.send(sendData.encode())