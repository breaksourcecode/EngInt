/********************************************************************************
** Form generated from reading UI file 'youdao002.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef YOUDAO002_H
#define YOUDAO002_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QTimeEdit>
#include <QtGui/QWidget>

#include <QTcpSocket>
#include <QString>
#include <QList>
#include <QVector>
#include <QWebView>
#include <QTimer>
#include <QTime>
#include <QListWidgetItem>

#include "MyQLineEdit.h"
#include "xml/ParseXML.h"
#include <QMap>

QT_BEGIN_NAMESPACE

class Ui_MainWindow : public QObject
{
	Q_OBJECT
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QPushButton *pushButton;
    MyQLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QFrame *frame;
	QWebView     *webView;
    QWidget *tab;
    QTextEdit *textEdit_2;
	QWebView  *webView_2;
    QGroupBox *groupBox_3;
    QListWidget *listWidget;
    QFrame *frame_5;
    QLCDNumber *lcdNumber_2;
    QTimeEdit *timeEdit_3;
    QWidget *tab_2;
	QWebView  *webView_3;
    QGroupBox *groupBox_4;
    QListView *listView;
	QListWidget *listWidget_2;

    QFrame *frame_2;
    QLCDNumber *lcdNumber;

    QTimeEdit *timeEdit;
	QTimer *timer;

private:
	QTcpSocket *socket;
	QVector<QString> wordsVector;
	QVector<QString> wordsContent;
	int pos; //描述缓冲单词位置
	QTime baseTime;
	QVector< QPair<QString,QDomElement>* > vec;
	QMap<int,QString> num_words;
	ParseXML *px;
	int level; //用于设置50个单词
public:
	Ui_MainWindow();
	~Ui_MainWindow();

	QString doConnectAndRead(QString order);
	void setWordsList(QString,QString);
	
	void setVec();
	void setNumWords();
	void reverseNumWords();
public slots:
	void setMainText();
	void setLineEdit();
	void forward();
	void backward();
	void setTime(int);
	void onTimeOut();
	void showWordItem(QListWidgetItem *);
	void showWordItem_2(QListWidgetItem*);
signals:
	void changed();
public:

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(589, 318);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(-10, 0, 601, 321));
        tabWidget->setMinimumSize(QSize(601, 321));
        tabWidget->setMaximumSize(QSize(601, 321));
        tabWidget->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(100, 100));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        pushButton = new QPushButton(tab_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(500, 0, 101, 31));
        lineEdit = new MyQLineEdit(tab_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 0, 361, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        pushButton_2 = new QPushButton(tab_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 0, 61, 31));
        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 0, 71, 31));
        frame = new QFrame(tab_3);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 30, 591, 261));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
		webView = new QWebView(frame);
		webView->setObjectName(QString::fromUtf8("webView"));
		webView->setGeometry(QRect(0,1,591,261));

        tabWidget->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));

		webView_2 = new QWebView(tab);
		webView_2->setObjectName(QString::fromUtf8("webView_2"));
		webView_2->setGeometry(QRect(200,30,401,261));

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 0, 201, 281));
        listWidget = new QListWidget(groupBox_3);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 30, 191, 261));
        frame_5 = new QFrame(groupBox_3);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(10, 0, 591, 31));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        lcdNumber_2 = new QLCDNumber(frame_5);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(0, 0, 191, 31));
        tabWidget->addTab(tab, QString());
        groupBox_3->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));

		webView_3 = new QWebView(tab_2);
		webView_3->setObjectName(QString::fromUtf8("webView_3"));
		webView_3->setGeometry(QRect(200,30,401,271));

        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 0, 201, 281));

		listWidget_2 = new QListWidget(groupBox_4);
		listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
		listWidget_2->setGeometry(QRect(10,31,191,261));

        frame_2 = new QFrame(groupBox_4);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 0, 591, 31));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        lcdNumber = new QLCDNumber(frame_2);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(0, 0, 191, 31));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);

		QObject::connect(lineEdit,SIGNAL(search()),this,SLOT(setMainText()));
		QObject::connect(pushButton,SIGNAL(clicked()),this,SLOT(setMainText()));
		QObject::connect(pushButton_2,SIGNAL(clicked()),this,SLOT(backward()));
		QObject::connect(pushButton_3,SIGNAL(clicked()),this,SLOT(forward()));
		QObject::connect(timer,SIGNAL(timeout()),this,SLOT(onTimeOut()));
		QObject::connect(tabWidget,SIGNAL(currentChanged(int)),this,SLOT(setTime(int)));
		QObject::connect(listWidget,SIGNAL(itemActivated(QListWidgetItem *)),this,SLOT(showWordItem(QListWidgetItem *)));
		QObject::connect(listWidget_2,SIGNAL(itemActivated(QListWidgetItem *)),this,SLOT(showWordItem_2(QListWidgetItem *)));
        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Youdao", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Go", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QString());
        pushButton_2->setText(QApplication::translate("MainWindow", "->", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "<-", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "                  Query                  ", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QString());

        listWidget->setSortingEnabled(false);

		QMap<int,QString>::Iterator sortedItems;
		for(sortedItems=num_words.begin();sortedItems!=num_words.end();++sortedItems)
		{
			if(level < 50)
			{
				listWidget_2->addItem(sortedItems.value());
				++level;
			} else {
				level = 0;
				break;
			}
		}
		level = 0;
		QMapIterator<int,QString> sort(num_words);
		sort.toBack();
		while(sort.hasPrevious())
		{
			sort.previous();
			listWidget->addItem(sort.value());
			if(level > 50)
			{
				break;
			}
			++level;
		}


        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "    High Frequency Words    ", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "      Low Frequency Words     ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // YOUDAO002_H
