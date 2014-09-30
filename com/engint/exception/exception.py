#-*- coding: utf-8 -*-


class CustomeException( Exception ):
    __module = None
    __msg  = None
    __detail = Exception()

    def __init__( self , module , msg , detail ):
        '''
        Constructor
        '''
        self.__module = module
        self.__msg    = msg
        self.__detail = detail
        
    def __str__(self):
        return " ".join([self.__module,self.__msg,self.__detail])
    
    
