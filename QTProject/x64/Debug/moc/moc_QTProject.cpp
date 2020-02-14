/****************************************************************************
** Meta object code from reading C++ file 'QTProject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../QTProject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QTProject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QTProject_t {
    QByteArrayData data[16];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTProject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTProject_t qt_meta_stringdata_QTProject = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QTProject"
QT_MOC_LITERAL(1, 10, 12), // "brushClicked"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "closeClicked"
QT_MOC_LITERAL(4, 37, 12), // "imageCapture"
QT_MOC_LITERAL(5, 50, 11), // "imageSaveAs"
QT_MOC_LITERAL(6, 62, 7), // "Newfile"
QT_MOC_LITERAL(7, 70, 7), // "version"
QT_MOC_LITERAL(8, 78, 10), // "paintEvent"
QT_MOC_LITERAL(9, 89, 12), // "QPaintEvent*"
QT_MOC_LITERAL(10, 102, 5), // "event"
QT_MOC_LITERAL(11, 108, 4), // "undo"
QT_MOC_LITERAL(12, 113, 4), // "redo"
QT_MOC_LITERAL(13, 118, 10), // "Screenshot"
QT_MOC_LITERAL(14, 129, 8), // "DrawLine"
QT_MOC_LITERAL(15, 138, 14) // "brushcountfunc"

    },
    "QTProject\0brushClicked\0\0closeClicked\0"
    "imageCapture\0imageSaveAs\0Newfile\0"
    "version\0paintEvent\0QPaintEvent*\0event\0"
    "undo\0redo\0Screenshot\0DrawLine\0"
    "brushcountfunc"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTProject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       6,    0,   78,    2, 0x0a /* Public */,
       7,    0,   79,    2, 0x0a /* Public */,
       8,    1,   80,    2, 0x0a /* Public */,
      11,    0,   83,    2, 0x0a /* Public */,
      12,    0,   84,    2, 0x0a /* Public */,
      13,    0,   85,    2, 0x0a /* Public */,
      14,    0,   86,    2, 0x0a /* Public */,
      15,    0,   87,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QTProject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QTProject *_t = static_cast<QTProject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->brushClicked(); break;
        case 1: _t->closeClicked(); break;
        case 2: _t->imageCapture(); break;
        case 3: _t->imageSaveAs(); break;
        case 4: _t->Newfile(); break;
        case 5: _t->version(); break;
        case 6: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 7: _t->undo(); break;
        case 8: _t->redo(); break;
        case 9: _t->Screenshot(); break;
        case 10: _t->DrawLine(); break;
        case 11: _t->brushcountfunc(); break;
        default: ;
        }
    }
}

const QMetaObject QTProject::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QTProject.data,
      qt_meta_data_QTProject,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QTProject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTProject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QTProject.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QTProject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
