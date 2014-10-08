#include "MyQLineEdit.h"

MyQLineEdit::MyQLineEdit(QWidget* parent): QLineEdit(parent)
{

}

void MyQLineEdit::keyPressEvent(QKeyEvent *e)
{
	int key = e->key();
	if( Qt::Key_Enter - 1 == key )
	{
		emit search();
	}
	QLineEdit::keyPressEvent(e);
}
