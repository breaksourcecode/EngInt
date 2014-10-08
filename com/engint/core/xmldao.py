#-*- coding: utf-8 -*-
from com.engint.setup import const
import time
import xml.etree.ElementTree as ET

class XMLDAO( object ):
    
    def __init__(self):
        
        self.tree = ET.parse(const.XMLFILE)
        self.root = self.tree.getroot()
        
    def save(self,word,pronounce,semantic):
        words = set()
        if word is not None:
            for child in self.root.iter(const.WORD):
                words.add(child.text)
                
            if word in words:
                self.update(word)
            else:
                self.append(word,pronounce,semantic)
        self.write()
    
    def append(self,word_,pronounce_,semantic_):
        entry = ET.SubElement(self.root,const.ENTRY)
        word = ET.SubElement(entry,const.WORD)
        word.text = word_
        word.set(const.COUNT,const.INITVAL)
        word.set(const.SEQUENCE,str(self.getSeq()))
        pronounce= ET.SubElement(entry,const.PRONOUNCE)
        pronounce.text = pronounce_
        semantic = ET.SubElement(entry,const.SEMANTIC)
        semantic.text = semantic_
        firsttime = ET.SubElement(entry,const.FIRSTTIME)
        firsttime.text = time.ctime()
        lasttime = ET.SubElement(entry,const.LASTTIME)
        lasttime.text = firsttime.text
        entry.tail = const.NEWLINE
    
    def getSeq(self):
        return len(self.root)
            
    def _append(self,parent,child):
        parent.append(child)
    
    
    def update(self,word):
        for entry in self.root.findall(const.ENTRY):
            for child in entry.findall(const.WORD):
                if child.text.strip() == word:
                    self._update(entry)
                    
    
    def _update(self,element):
        word = element.find(const.WORD)
        count = int(word.get(const.COUNT)) + 1
        word.set(const.COUNT,str(count))
        lasttime = element.find(const.LASTTIME)
        lasttime.text = time.ctime()
    
    def delete(self,element):
        if element is not None and  element in self.root.iter(element.tag):
            self.tree.remove(element)
    
    def read(self,tag):
        elements = list()
        if tag is not None:
            for child in self.root.iter(tag):
                elements.append(child)
        return elements
    
    def write(self):
        self.tree.write(const.XMLFILE)
    
    def flush(self):
        self.write()
    
if __name__ == '__main__':
    xmldao = XMLDAO()
    a = xmldao.read('word')
    print(a)
    l = xmldao.getSeq()
    print(l)
    xmldao.save('semantic', 'hello', 'nihao')