#-*- coding : utf-8 -*-
from com.engint.setup import const

class Conclusion( object ):
    '''根据查询的结果，对结果进行分析：
    如果返回的字典中含有errorCode,basic,web,translation
    和query五个key，则说明此次查询属于正常查询;
    如果返回的字典中只含有errorcode,web,transltaion
    和query四个key，则说明此次查询不属于正常查询，可能是单词不合法，例：查询单词是ahy;
    如果查询单词为拼音，例zhang，则五个key都存在，此时basic字典中只有解释，没有音标读音
    '''
    def __init__(self,conclusion):
        self.conclusion = conclusion
    
    def getKeys(self):
        if self.conclusion is not None:
            return self.conclusion.keys()
    
    def isNormal(self):
        keys = self.getKeys()
        if const.BASIC in keys:
            return True
        else:
            return False
    
    def isPhonetic(self):
        if self.isNormal():
            if const.PHONETIC in self.conclusion[const.BASIC].keys():
                return True
            else:
                return False
