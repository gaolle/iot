/****************************************************************************
** Meta object code from reading C++ file 'picture.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../picture.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'picture.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PICTURE[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      39,    8,    8,    8, 0x08,
      65,    8,    8,    8, 0x08,
      89,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PICTURE[] = {
    "PICTURE\0\0on_pushButton_start_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_clicked()\0autodisplay()\0"
};

void PICTURE::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PICTURE *_t = static_cast<PICTURE *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_start_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->autodisplay(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData PICTURE::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PICTURE::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PICTURE,
      qt_meta_data_PICTURE, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PICTURE::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PICTURE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PICTURE::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PICTURE))
        return static_cast<void*>(const_cast< PICTURE*>(this));
    return QDialog::qt_metacast(_clname);
}

int PICTURE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
