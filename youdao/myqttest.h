#ifndef MYQTTEST_H
#define MYQTTEST_H

#include <QtGui/QDialog>
#include "youdao.h"

class myQtTest : public QMainWindow
{
    Q_OBJECT

public:
    myQtTest(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~myQtTest();

private:
    Ui::MainWindow ui;

};

#endif // MYQTTEST_H
