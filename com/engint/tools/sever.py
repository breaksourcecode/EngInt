#-*- coding: utf-8 -*-
from com.engint.manager import Manager
from com.engint.setup import const
from com.engint.tools.conlusion import Conclusion
from com.engint.tools.conversion import Conversion
from com.engint.tools.html import Html
import re
import socket

class Server(object):
    '''
    该类作为一个服务类存在，为客户端提供服务。所以的处理都在这个类中体现。客户端仅仅作为展示层。
    '''
    def __init__(self):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.bind(const.ADDRESS)
        self.sock.listen(5)
        
        #add Manager to manager requestion
        self.manager = Manager()
        self.convert = Conversion()
        self.html = Html()

    def server(self):
        while(True):
            self.connection, self.address = self.sock.accept()
            try:
                buf = self.connection.recv(1024)
                if buf is not None and buf.strip() != b'':
                    queryWord = self.convert.bytesToString(buf.strip())
                    isMatch = re.match(const.PATTERN,queryWord)
                    if isMatch:
                        self.manager.query(queryWord)
                        conclusion = Conclusion(self.manager.data.getData())
                        if self.manager.data.getErrorCode() != '0' and conclusion.isNormal() and conclusion.isPhonetic():
                            br = self.html.br()
                            body_one = self.html.body(br + str(self.manager.data.getPhoneticList()) + br)
                            body_two = self.html.body(br + str(self.manager.data.getExplainsList()))
                            view = self.html.html(body_one + body_two)
                            self.connection.send(self.convert.stringToBytes(view))
                            self.manager.save(self.manager.data.getQuery(), \
                                              self.manager.data.getPhonetic(),\
                                               str(self.manager.data.getExplains()))
                        else:
                            self.connection.send(self.convert.stringToBytes(const.NotWord))
                    else:
                        self.connection.send(self.convert.stringToBytes(const.IlligalWord))
                else:
                    self.connection.send(self.convert.stringToBytes("!ok"))
                self.__dele__()
            except socket.timeout:
                print('time out')
                
    def __dele__(self):
        self.connection.close()

if __name__ == '__main__':
    s = Server()
    s.server()