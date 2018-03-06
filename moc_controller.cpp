/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[17];
    char stringdata0[241];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Controller"
QT_MOC_LITERAL(1, 11, 18), // "notifyTotalThreads"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 22), // "notifyPThreadCompleted"
QT_MOC_LITERAL(4, 54, 24), // "notifyQRunnableCompleted"
QT_MOC_LITERAL(5, 79, 22), // "notifyComputeCompleted"
QT_MOC_LITERAL(6, 102, 11), // "PThreadTime"
QT_MOC_LITERAL(7, 114, 13), // "QRunnableTime"
QT_MOC_LITERAL(8, 128, 23), // "notifyProgressCompleted"
QT_MOC_LITERAL(9, 152, 15), // "PThreadProgress"
QT_MOC_LITERAL(10, 168, 17), // "QRunnableProgress"
QT_MOC_LITERAL(11, 186, 14), // "readWriteError"
QT_MOC_LITERAL(12, 201, 12), // "errorMessage"
QT_MOC_LITERAL(13, 214, 8), // "getPaths"
QT_MOC_LITERAL(14, 223, 5), // "pathA"
QT_MOC_LITERAL(15, 229, 5), // "pathB"
QT_MOC_LITERAL(16, 235, 5) // "pathC"

    },
    "Controller\0notifyTotalThreads\0\0"
    "notifyPThreadCompleted\0notifyQRunnableCompleted\0"
    "notifyComputeCompleted\0PThreadTime\0"
    "QRunnableTime\0notifyProgressCompleted\0"
    "PThreadProgress\0QRunnableProgress\0"
    "readWriteError\0errorMessage\0getPaths\0"
    "pathA\0pathB\0pathC"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    2,   52,    2, 0x06 /* Public */,
       8,    2,   57,    2, 0x06 /* Public */,
      11,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    3,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::QString,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   14,   15,   16,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Controller *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->notifyTotalThreads(); break;
        case 1: _t->notifyPThreadCompleted(); break;
        case 2: _t->notifyQRunnableCompleted(); break;
        case 3: _t->notifyComputeCompleted((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->notifyProgressCompleted((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->readWriteError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->getPaths((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Controller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::notifyTotalThreads)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Controller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::notifyPThreadCompleted)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Controller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::notifyQRunnableCompleted)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Controller::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::notifyComputeCompleted)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Controller::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::notifyProgressCompleted)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Controller::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::readWriteError)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject Controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Controller.data,
      qt_meta_data_Controller,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(const_cast< Controller*>(this));
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Controller::notifyTotalThreads()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Controller::notifyPThreadCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Controller::notifyQRunnableCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Controller::notifyComputeCompleted(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Controller::notifyProgressCompleted(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Controller::readWriteError(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
