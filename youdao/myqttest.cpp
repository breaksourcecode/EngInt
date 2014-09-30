#include "myqttest.h"
#include <QTextCodec>
myQtTest::myQtTest(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
    ui.setupUi(this);
	QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
	
	Qt::WindowFlags  windowflags= 0;
	windowflags |= Qt::WindowMinimizeButtonHint;
	windowflags |= Qt::WindowCloseButtonHint;
	this->setWindowFlags(windowflags);
	this->setFixedSize(this->width(),this->height());
}

myQtTest::~myQtTest()
{
}
