#-*- coding : utf-8 -*-

'''
    此文件主要用于整个工程中的常量定义
'''
#�����е�����API��ַ
from com.engint.tools import html
keyfrom = r'halfinterpreter'
key = r'1317759079'
URL = r'http://fanyi.youdao.com/openapi.do?keyfrom='+keyfrom+'&key='+key+'&type=data&doctype=json&version=1.1&q='

#Youdao��������
QUERY = 'query'
ERRORCODE = 'errorCode'
WEB = 'web'
TRANSLATION = 'translation'
BASIC = 'basic'
EXPLAINS = 'explains'
PHONETIC = 'phonetic'
UKPHONETIC = 'uk-phonetic'
USPHONETIC = 'us-phonetic'

#XMLDAO��������
XMLFILE = '/home/update/test.xml'
SEQUENCE = 'sequence'
COUNT = 'count'
NEWLINE = '\n'
INITVAL = '1'
ENTRY = 'entry'
PRONOUNCE = 'pronounce'
WORD = 'word'
SEMANTIC =  'semantic'
FIRSTTIME = 'firsttime'
LASTTIME = 'lasttime'

#�ͻ�������
IP = 'localhost'
PORT = 8001
ADDRESS = tuple((IP,PORT))
BUFFERSIZE = 1024

#����������ʽ
PATTERN = r'^[a-zA-Z]+$'

#请输入单词
NotWord = html.HTML + html.BODY+ html.BR +"请输入单词!" +html.BODY_ +html.HTML_
#单词不合法
IlligalWord = html.HTML + html.BODY+ html.BR +"单词不合法!" +html.BODY_ +html.HTML_