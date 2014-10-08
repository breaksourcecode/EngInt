#-*- coding: utf-8 -*-
from com.engint.core.metadata import Data
from com.engint.core.xmldao import XMLDAO
from com.engint.core.youdao import Youdao

class Manager( object ):
    
    def __init__(self):
        
        self.xmldao = XMLDAO()
        self.data = Data()
        self.youdao = Youdao()
        
    def save(self,word,pronounce,semantic):
        self.xmldao.save(word, pronounce, semantic)
    
    def read(self,word):
        pass
    
    def query(self,word):
        #youdao = Youdao()
        self.data.setData(self.youdao.query(word))  #每次查询，把查询结果set到data中，然后通过data结构体获取结果
        
    def parseParameters(self):
        self.query('hello')
        parameters = self.data.getBasic()  
        print(parameters)
        
        if self.data.getErrorCode() == '0':
            pass
        else:
            self.save(self.data.getQuery(), self.data.getPhonetic(), str(self.data.getExplains()))

        
if __name__ == '__main__':
    m = Manager()
    m.parseParameters()
        