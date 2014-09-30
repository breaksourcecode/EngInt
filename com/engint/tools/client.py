#-*- coding: utf-8 -*-
from com.engint.setup import const
import socket

class Client( object ):
    
    def __init__(self):
        self.sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        
    
    def connect(self):
        self.sock.connect(const.ADDRESS)
        
    def send(self,msg):
        data = bytes(msg,encoding='utf8')
        self.sock.send(data)
    
    def receive(self):
        buff = self.sock.recv(const.BUFFERSIZE)
        return str(buff,encoding='utf8')
    
    def __dele__(self):
        self.sock.close()
    
if __name__ == '__main__':
    c = Client()
    c.connect()
    c.send('hello world......')
    print(c.receive())
    c.__dele__()
    