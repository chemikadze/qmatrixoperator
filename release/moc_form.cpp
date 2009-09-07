/****************************************************************************
** Meta object code from reading C++ file 'form.h'
**
** Created: Fri 24. Apr 02:08:44 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../form.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MatrixForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x0a,
      36,   34,   11,   11, 0x0a,
      56,   12,   11,   11, 0x0a,
      76,   34,   11,   11, 0x0a,
      96,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MatrixForm[] = {
    "MatrixForm\0\0n\0resizeMatrixNA(int)\0m\0"
    "resizeMatrixMA(int)\0resizeMatrixNB(int)\0"
    "resizeMatrixMB(int)\0calculateMatrix()\0"
};

const QMetaObject MatrixForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MatrixForm,
      qt_meta_data_MatrixForm, 0 }
};

const QMetaObject *MatrixForm::metaObject() const
{
    return &staticMetaObject;
}

void *MatrixForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MatrixForm))
        return static_cast<void*>(const_cast< MatrixForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int MatrixForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: resizeMatrixNA((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: resizeMatrixMA((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: resizeMatrixNB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: resizeMatrixMB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: calculateMatrix(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
