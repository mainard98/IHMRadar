/****************************************************************************
** Meta object code from reading C++ file 'ihm6843.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ihm6843.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ihm6843.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IHM6843_t {
    QByteArrayData data[12];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IHM6843_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IHM6843_t qt_meta_stringdata_IHM6843 = {
    {
QT_MOC_LITERAL(0, 0, 7), // "IHM6843"
QT_MOC_LITERAL(1, 8, 15), // "on_stop_clicked"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 16), // "on_start_clicked"
QT_MOC_LITERAL(4, 42, 15), // "clutter_clicked"
QT_MOC_LITERAL(5, 58, 18), // "cfar_range_clicked"
QT_MOC_LITERAL(6, 77, 20), // "cfar_doppler_clicked"
QT_MOC_LITERAL(7, 98, 7), // "quitter"
QT_MOC_LITERAL(8, 106, 10), // "change_cfg"
QT_MOC_LITERAL(9, 117, 8), // "filename"
QT_MOC_LITERAL(10, 126, 11), // "changeAxisZ"
QT_MOC_LITERAL(11, 138, 17) // "change_backupFile"

    },
    "IHM6843\0on_stop_clicked\0\0on_start_clicked\0"
    "clutter_clicked\0cfar_range_clicked\0"
    "cfar_doppler_clicked\0quitter\0change_cfg\0"
    "filename\0changeAxisZ\0change_backupFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IHM6843[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    1,   65,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void IHM6843::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IHM6843 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_stop_clicked(); break;
        case 1: _t->on_start_clicked(); break;
        case 2: _t->clutter_clicked(); break;
        case 3: _t->cfar_range_clicked(); break;
        case 4: _t->cfar_doppler_clicked(); break;
        case 5: _t->quitter(); break;
        case 6: _t->change_cfg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->changeAxisZ(); break;
        case 8: _t->change_backupFile(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject IHM6843::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_IHM6843.data,
    qt_meta_data_IHM6843,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IHM6843::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IHM6843::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IHM6843.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int IHM6843::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
