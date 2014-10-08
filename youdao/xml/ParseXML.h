#include <QtXml>
#include <QFile>
#include <QDebug>
#include <QIODevice>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNodeList>

#include <QPair>
#include <QVector>

class ParseXML {
	
	public:
		ParseXML(QString fileName);
		~ParseXML();
		
		QDomDocument getDocument();
		QDomElement getRootElement();
		
		void setList();
		//QVector<QPair<QString,QDomElement> *> getList();
		void getList(QVector<QPair<QString,QDomElement>* > *des);
		void test();

		QString getWord(QDomElement);
		int		getCount(QDomElement);
		QString getPronounce(QDomElement);
		QString getSemantic(QDomElement);
		QString getFirstTime(QDomElement);
		QString getLastTime(QDomElement);
	
	private:
		QVector<QPair<QString,QDomElement> > meta;
		QString fileName;
		QDomDocument document;
		QDomNodeList items;
		QDomElement root;
};
