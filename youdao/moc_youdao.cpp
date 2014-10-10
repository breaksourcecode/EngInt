/****************************************************************************
** Meta object code from reading C++ file 'youdao.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "youdao.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'youdao.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ui_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      25,   14,   14,   14, 0x0a,
      39,   14,   14,   14, 0x0a,
      53,   14,   14,   14, 0x0a,
      63,   14,   14,   14, 0x0a,
      74,   14,   14,   14, 0x0a,
      87,   14,   14,   14, 0x0a,
      99,   14,   14,   14, 0x0a,
     130,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Ui_MainWindow[] = {
    "Ui_MainWindow\0\0changed()\0setMainText()\0"
    "setLineEdit()\0forward()\0backward()\0"
    "setTime(int)\0onTimeOut()\0"
    "showWordItem(QListWidgetItem*)\0"
    "showWordItem_2(QListWidgetItem*)\0"
};

void Ui_MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Ui_MainWindow *_t = static_cast<Ui_MainWindow *>(_o);
        switch (_id) {
        case 0: _t->changed(); break;
        case 1: _t->setMainText(); break;
        case 2: _t->setLineEdit(); break;
        case 3: _t->forward(); break;
        case 4: _t->backward(); break;
        case 5: _t->setTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onTimeOut(); break;
        case 7: _t->showWordItem((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->showWordItem_2((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Ui_MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Ui_MainWindow::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Ui_MainWindow,
      qt_meta_data_Ui_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Ui_MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Ui_MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Ui_MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ui_MainWindow))
        return static_cast<void*>(const_cast< Ui_MainWindow*>(this));
    return QObject::qt_metacast(_clname);
}

int Ui_MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Ui_MainWindow::changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
