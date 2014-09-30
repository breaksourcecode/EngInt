#-*- coding:utf-8 -*-
from com.engint.core.youdao import Youdao
from com.engint.setup import const

SPACE = '&nbsp'
class Data( object ):
    '''
    该类是系统的主要数据结构。查询的结果保存在这个类中，然后对相应信息进行提取。
    '''
    def __init__(self):
        pass
    
    def setData(self,rawstring):
        self.rawstring = rawstring
    
    def getData(self):
        return self.rawstring
        
    def getQuery(self):
        return self.rawstring[const.QUERY]
    
    def getErrorCode(self):
        return self.rawstring[const.ERRORCODE]
    
    def getWeb(self):
        return self.rawstring[const.WEB]
    
    def getTranslation(self):
        return self.rawstring[const.TRANSLATION]

    def getBasic(self):
        return self.rawstring[const.BASIC]
    
    def getExplainsList(self):
        items = self.getExplains()
        explaions = ''
        if items is not None:
            for item in items:
                explaions += item + '<br>'
        return explaions
    
    def getExplains(self):
        basic = self.getBasic()
        return basic[const.EXPLAINS]
    
    def getPhoneticList(self):
        phonetic = '美:[' + self.getUsPhonetic() + ']' + SPACE*3
        phonetic += '英:[' + self.getUkPhonetic() + ']'+ SPACE*3
        return phonetic
    
    def getPhonetic(self):
        basic = self.getBasic()
        return basic[const.PHONETIC]
    
    def getUkPhonetic(self):
        basic = self.getBasic()
        return basic[const.UKPHONETIC]
    
    def getUsPhonetic(self):
        basic = self.getBasic()
        return basic[const.USPHONETIC]
    
    def getWebValue(self):
        web = self.getWeb()
        return web[0]['value']
    
if __name__ == '__main__':
    d = Data()
    youdao = Youdao()
    a = youdao.query('funny')
    d.setData(a)
    
    print(d.getWebValue())
    print(d.getTranslation())
    print(d.getUkPhonetic())
    print(d.getBasic())
    print(d.getQuery())
    print(d.getPhonetic())
    print(d.getExplains())
    
    