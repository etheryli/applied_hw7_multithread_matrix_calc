/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[365];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "sendPaths"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 5), // "pathA"
QT_MOC_LITERAL(4, 28, 5), // "pathB"
QT_MOC_LITERAL(5, 34, 5), // "pathC"
QT_MOC_LITERAL(6, 40, 19), // "allThreadsCompleted"
QT_MOC_LITERAL(7, 60, 12), // "progressDone"
QT_MOC_LITERAL(8, 73, 15), // "PThreadProgress"
QT_MOC_LITERAL(9, 89, 17), // "QRunnableProgress"
QT_MOC_LITERAL(10, 107, 11), // "computeDone"
QT_MOC_LITERAL(11, 119, 11), // "PThreadTime"
QT_MOC_LITERAL(12, 131, 13), // "QRunnableTime"
QT_MOC_LITERAL(13, 145, 13), // "errorReceived"
QT_MOC_LITERAL(14, 159, 12), // "errorMessage"
QT_MOC_LITERAL(15, 172, 24), // "on_MatrixAButton_clicked"
QT_MOC_LITERAL(16, 197, 24), // "on_MatrixBButton_clicked"
QT_MOC_LITERAL(17, 222, 24), // "on_MatrixCButton_clicked"
QT_MOC_LITERAL(18, 247, 34), // "on_MatrixCLineEdit_editingFin..."
QT_MOC_LITERAL(19, 282, 24), // "on_ComputeButton_clicked"
QT_MOC_LITERAL(20, 307, 24), // "updatePThreadProgressBar"
QT_MOC_LITERAL(21, 332, 5), // "value"
QT_MOC_LITERAL(22, 338, 26) // "updateQRunnableProgressBar"

    },
    "MainWindow\0sendPaths\0\0pathA\0pathB\0"
    "pathC\0allThreadsCompleted\0progressDone\0"
    "PThreadProgress\0QRunnableProgress\0"
    "computeDone\0PThreadTime\0QRunnableTime\0"
    "errorReceived\0errorMessage\0"
    "on_MatrixAButton_clicked\0"
    "on_MatrixBButton_clicked\0"
    "on_MatrixCButton_clicked\0"
    "on_MatrixCLineEdit_editingFinished\0"
    "on_ComputeButton_clicked\0"
    "updatePThreadProgressBar\0value\0"
    "updateQRunnableProgressBar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   81,    2, 0x0a /* Public */,
       7,    2,   82,    2, 0x0a /* Public */,
      10,    2,   87,    2, 0x0a /* Public */,
      13,    1,   92,    2, 0x0a /* Public */,
      15,    0,   95,    2, 0x08 /* Private */,
      16,    0,   96,    2, 0x08 /* Private */,
      17,    0,   97,    2, 0x08 /* Private */,
      18,    0,   98,    2, 0x08 /* Private */,
      19,    0,   99,    2, 0x08 /* Private */,
      20,    1,  100,    2, 0x08 /* Private */,
      22,    1,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int,   21,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendPaths((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->allThreadsCompleted(); break;
        case 2: _t->progressDone((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->computeDone((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->errorReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_MatrixAButton_clicked(); break;
        case 6: _t->on_MatrixBButton_clicked(); break;
        case 7: _t->on_MatrixCButton_clicked(); break;
        case 8: _t->on_MatrixCLineEdit_editingFinished(); break;
        case 9: _t->on_ComputeButton_clicked(); break;
        case 10: _t->updatePThreadProgressBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->updateQRunnableProgressBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendPaths)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sendPaths(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
