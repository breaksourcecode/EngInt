#-*- coding : utf-8 -*-
from com.engint.setup import const
from urllib.request import urlopen
import json

class Youdao( object ):
    '''
    该类负责利用有道API获取查询结果。
    '''
    def __init__(self):
        
        self.url = const.URL

    def query(self,word):
        if word is not None:
            url = self.url + word
        file = urlopen(url)
        bytedata = file.read()
        return json.loads(bytedata.decode())
        
if __name__ == '__main__':
    
    youdao = Youdao()
    a = youdao.query('zhang')

    print(type(a))
    print(a)
   # print('basic'+ str(a['basic']))
    #print(a['web'])
    #print(a['translation'])
    #print(a['errorCode'])
    #print(a['query'])


#errorCode
#web
#translation
#basic
#query

#{'errorCode': 0, 
#'web': [{'key': 'Hello', 'value': ['你好', '您好', '哈啰']}, {'key': 'Hello Kitty', 'value': ['凯蒂猫', '昵称', '匿称']}, {'key': 'Hello Bebe', 'value': ['哈乐哈乐', '乐扣乐扣']}], 
#'translation': ['你好'],
#'basic': {'us-phonetic': 'hɛˈlo, hə-', 'uk-phonetic': "hə'ləʊ; he-", 'phonetic': "hə'ləʊ; he-", 'explains': ['n. 表示问候， 惊奇或唤起注意时的用语', 'int. 喂；哈罗', 'n. (Hello)人名；(法)埃洛']}, 
#'query': 'hello'}
