#-*- coding : utf-8 -*-

class Conversion( object ):
    
    def __init__(self):
        pass
    
    def stringToBytes(self,str):
        if str is not None:
            return bytes(str,encoding="utf8")
        
    def bytesToString(self,byt):
        if byt is not None:
            return str(byt,encoding="utf8")
        

if __name__ == "__main__":
    a = b'123'
    print(type(a))
    convert = Conversion()
    b = convert.bytesToString(a)
    print(type(b))
    c = convert.stringToBytes(b)
    print(type(c))