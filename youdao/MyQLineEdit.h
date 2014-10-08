#include <QLineEdit>
#include <QObject>
#include <QKeyEvent>

class MyQLineEdit : public QLineEdit
{
	Q_OBJECT
	
	public:
		MyQLineEdit(QWidget* parent);
	protected:
		virtual void keyPressEvent(QKeyEvent *e);
	signals:
		void search();
};

