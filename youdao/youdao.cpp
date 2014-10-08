#include "youdao.h"
#include <QDebug>
#include <QTextCodec>

Ui_MainWindow::Ui_MainWindow():pos(0),level(0)
{
	socket = new QTcpSocket(this);
	//socket->connectToHost("localhost",8001);

	baseTime = QTime::currentTime();
	timer = new QTimer();
	timer->setInterval(1000);
	timer->start();
	
	px = new ParseXML("../.dict.xml");
	setVec();
	setNumWords();
}

Ui_MainWindow::~Ui_MainWindow()
{
     //   socket->close();
}

void Ui_MainWindow::setMainText()
{

	QString str = doConnectAndRead(lineEdit->text());
	
	if(str.toStdString() != "notconnected")
	{
		webView->setHtml(str);
	} else {
		QString tips = "<html><body><br> please check service... </body></html>";
		webView->setHtml(tips);
	}
}

QString Ui_MainWindow::doConnectAndRead(QString order)
{
	QString string;
	socket->connectToHost("localhost",8001);
	if(socket->waitForConnected(5000))
    {
        socket->write(order.toUtf8());
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
		string = socket->readAll();
		

		if(order.trimmed() != "" && string.trimmed() != "") 
		{
			setWordsList(order.trimmed(),string.trimmed());//保存查询的单词，用于快捷查找
		}

        socket->close();
    } else {
        qDebug() << " not connected";
		return "notconnected";
    }

	return string;
}

void Ui_MainWindow::setWordsList(QString word,QString content)
{
	wordsVector.push_back(word);
	wordsContent.push_back(content);
	pos = wordsVector.size() - 1;
}

void Ui_MainWindow::setLineEdit()
{
	if(wordsVector.size() > 0) 
	{
		lineEdit->setText(wordsVector.front());
	}
}

void Ui_MainWindow::forward()
{
	if(pos > 0)
	{
		lineEdit->setText(wordsVector[pos - 1]);
		webView->setHtml(wordsContent[pos - 1]);
		pos -= 1;
	}
}

void Ui_MainWindow::backward()
{
	if( pos < wordsVector.size() - 1)
	{
		lineEdit->setText(wordsVector[pos + 1]);
		webView->setHtml(wordsContent[pos + 1]);
		pos += 1;
	}

}

void Ui_MainWindow::setTime(int noUse)
{
	QTime time = QTime::currentTime();
	baseTime = time;
}

void Ui_MainWindow::onTimeOut()
{
	
	QTime time = QTime::currentTime();
	QTime start = QTime(0,0,1);
	int interval = baseTime.msecsTo(time);
	interval = interval/1000;
	start = start.addSecs(interval);
	lcdNumber_2->display(start.toString("hh:mm:ss"));
	lcdNumber->display(start.toString("hh:mm:ss"));
}

void Ui_MainWindow::showWordItem(QListWidgetItem *it)
{
	int index = 0;
	for(int i=0;i<vec.size();++i)
	{
		if(vec[i]->first == it->text())
		{
			index = i;
			break;
		}
	}
	webView_2->setHtml(px->getSemantic(vec[index]->second));

}


void Ui_MainWindow::showWordItem_2(QListWidgetItem *it)
{
	int index = 0;
	for(int i=0;i<vec.size();++i)
	{
		if(vec[i]->first == it->text())
		{
			index = i;
			break;
		}
	}
	webView_3->setHtml(px->getSemantic(vec[index]->second));	

}

void Ui_MainWindow::setVec()
{
	px->getList(&vec);
}

void Ui_MainWindow::setNumWords()
{
	
	for(int i=0;i<vec.count();++i)
	{
		num_words.insert(px->getCount(vec[i]->second),vec[i]->first);
	}

}

void Ui_MainWindow::reverseNumWords()
{
	
}
