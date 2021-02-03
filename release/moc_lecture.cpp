/****************************************************************************
** Meta object code from reading C++ file 'lecture.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../lecture.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lecture.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_lecture_t {
    QByteArrayData data[12];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_lecture_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_lecture_t qt_meta_stringdata_lecture = {
    {
QT_MOC_LITERAL(0, 0, 7), // "lecture"
QT_MOC_LITERAL(1, 8, 9), // "RangePlot"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 15), // "QVector<double>"
QT_MOC_LITERAL(4, 35, 13), // "RangePlot6843"
QT_MOC_LITERAL(5, 49, 6), // "breath"
QT_MOC_LITERAL(6, 56, 5), // "heart"
QT_MOC_LITERAL(7, 62, 5), // "chest"
QT_MOC_LITERAL(8, 68, 8), // "dataXYZV"
QT_MOC_LITERAL(9, 77, 24), // "QVector<QVector<float> >"
QT_MOC_LITERAL(10, 102, 9), // "reception"
QT_MOC_LITERAL(11, 112, 5) // "trame"

    },
    "lecture\0RangePlot\0\0QVector<double>\0"
    "RangePlot6843\0breath\0heart\0chest\0"
    "dataXYZV\0QVector<QVector<float> >\0"
    "reception\0trame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_lecture[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       4,    3,   54,    2, 0x06 /* Public */,
       5,    1,   61,    2, 0x06 /* Public */,
       6,    1,   64,    2, 0x06 /* Public */,
       7,    1,   67,    2, 0x06 /* Public */,
       8,    2,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, QMetaType::Double,    2,    2,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,   11,

       0        // eod
};

void lecture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<lecture *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RangePlot((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 1: _t->RangePlot6843((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 2: _t->breath((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->heart((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->chest((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->dataXYZV((*reinterpret_cast< QVector<QVector<float> >(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->reception((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<float> > >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (lecture::*)(QVector<double> , QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&lecture::RangePlot)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (lecture::*)(QVector<double> , QVector<double> , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&lecture::RangePlot6843)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (lecture::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&lecture::breath)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (lecture::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&lecture::heart)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (lecture::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&lecture::chest)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (lecture::*)(QVector<QVector<float>> , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&lecture::dataXYZV)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject lecture::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_lecture.data,
    qt_meta_data_lecture,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *lecture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lecture::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_lecture.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int lecture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void lecture::RangePlot(QVector<double> _t1, QVector<double> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void lecture::RangePlot6843(QVector<double> _t1, QVector<double> _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void lecture::breath(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void lecture::heart(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void lecture::chest(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void lecture::dataXYZV(QVector<QVector<float>> _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
