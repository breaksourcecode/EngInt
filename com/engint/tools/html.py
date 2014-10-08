#-*- coding : utf-8 -*-

HTML = "<html>"
HTML_ = "</html>"
HEAD = "<head>"
HEAD_ = "</head>"
BODY = "<body>"
BODY_ = "</body>"
BR = "<br>"
HR = "<hr>"

class Html( object ):
    '''
    python负责后台处理，所以的信息都在后台进行拼接组合。该类负责对各种信息进行包装。
    '''
    def __init__(self):
        pass
    
    def html(self,content):
        if content is not None:
            return HTML + content + HTML_
    
    def head(self,content):
        if content is not None:
            return HEAD + content + HEAD_
    
    def body(self,content):
        if content is not None:
            return BODY + content + BODY_
    
    def br(self):
        return BR
    
    def hr(self):
        return HR

