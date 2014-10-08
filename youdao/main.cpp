#include "myqttest.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myQtTest w;    
    w.show();
    return a.exec();
}
