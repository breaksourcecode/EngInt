#include "ParseXML.h"
#include <stdio.h>


ParseXML::ParseXML(QString fileName)
{
	this->fileName = fileName;
}


QDomDocument ParseXML::getDocument()
{
	QFile file(fileName);
	file.open(QIODevice::ReadOnly);
	int errLin = 0;
	int errCol = 0;
	QString strError;
	if(!document.setContent(&file,false,&strError,&errLin,&errCol))
	{
		qDebug()<<QString(errLin);
		exit(-1);
	}
	if(document.isNull())
	{
		qDebug()<<"document is null";
		exit(-1);
	}

	return document;
}

QDomElement ParseXML::getRootElement()
{
	QDomDocument doc = getDocument();
	root = doc.documentElement();
	return root;
}

void ParseXML::test()
{
	QDomElement root = getRootElement();
	qDebug()<<"  ----->"<<root.tagName();
	qDebug()<<"++++++++++++++++";
	
	setList();
	qDebug()<<"meta-->"<<meta.size();

	for(int i=0;i<meta.size();++i)
	{
		qDebug()<< meta[i].first<<"   "<<getLastTime(meta[i].second)<<"  " <<getCount(meta[i].second);
	}
}

ParseXML::~ParseXML()
{
	
}

void ParseXML::setList()
{	
	QDomElement root = getRootElement();
	QDomNodeList entrys = root.elementsByTagName("entry");
	for(int i=0;i<entrys.count();++i)
	{
		QDomNode node = entrys.at(i);
		QDomElement e = node.toElement();
		QDomElement wordChild = e.firstChildElement();
		QPair<QString, QDomElement> elem(wordChild.text(),e);
		meta.push_back(elem);

	}
}

//QVector<QPair<QString,QDomElement>* > ParseXML::getList()
void ParseXML::getList(QVector<QPair<QString,QDomElement>* > *tmp)
{
	setList();
	for(int i=0;i<meta.size();++i)
	{
		tmp->push_back(new QPair<QString,QDomElement>(meta[i].first,meta[i].second));
	}
}

QString ParseXML::getWord(QDomElement e)
{
	QDomElement elem = e.firstChildElement("word");
	return elem.text();
}

QString ParseXML::getPronounce(QDomElement e)
{
	QDomElement elem = e.firstChildElement("pronounce");
	return elem.text();
}

QString ParseXML::getSemantic(QDomElement e)
{
	QDomElement elem = e.firstChildElement("semantic");
	return elem.text();
}


QString ParseXML::getFirstTime(QDomElement e)
{
	QDomElement elem = e.firstChildElement("firsttime");
	return elem.text();
}


QString ParseXML::getLastTime(QDomElement e)
{
	QDomElement elem = e.firstChildElement("lasttime");
	return elem.text();
}

int ParseXML::getCount(QDomElement e)
{
	QDomElement elem = e.firstChildElement("word");
	QString count = elem.attribute("count");
	return count.toInt();
}
