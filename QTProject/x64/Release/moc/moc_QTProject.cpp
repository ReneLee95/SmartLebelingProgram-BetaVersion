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
    QByteArrayData data[22];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTProject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTProject_t qt_meta_stringdata_QTProject = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QTProject"
QT_MOC_LITERAL(1, 10, 7), // "clicked"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 9), // "imageOpen"
QT_MOC_LITERAL(4, 29, 12), // "closeClicked"
QT_MOC_LITERAL(5, 42, 12), // "imageCapture"
QT_MOC_LITERAL(6, 55, 11), // "imageSaveAs"
QT_MOC_LITERAL(7, 67, 7), // "Newfile"
QT_MOC_LITERAL(8, 75, 7), // "version"
QT_MOC_LITERAL(9, 83, 4), // "undo"
QT_MOC_LITERAL(10, 88, 4), // "redo"
QT_MOC_LITERAL(11, 93, 10), // "Screenshot"
QT_MOC_LITERAL(12, 104, 8), // "DrawLine"
QT_MOC_LITERAL(13, 113, 14), // "brushcountfunc"
QT_MOC_LITERAL(14, 128, 10), // "fontsizeup"
QT_MOC_LITERAL(15, 139, 12), // "fontsizedown"
QT_MOC_LITERAL(16, 152, 14), // "colorRedselect"
QT_MOC_LITERAL(17, 167, 15), // "colorBlueselect"
QT_MOC_LITERAL(18, 183, 16), // "colorBlackselect"
QT_MOC_LITERAL(19, 200, 8), // "DrawRect"
QT_MOC_LITERAL(20, 209, 7), // "DrawCir"
QT_MOC_LITERAL(21, 217, 5) // "Erase"

    },
    "QTProject\0clicked\0\0imageOpen\0closeClicked\0"
    "imageCapture\0imageSaveAs\0Newfile\0"
    "version\0undo\0redo\0Screenshot\0DrawLine\0"
    "brushcountfunc\0fontsizeup\0fontsizedown\0"
    "colorRedselect\0colorBlueselect\0"
    "colorBlackselect\0DrawRect\0DrawCir\0"
    "Erase"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTProject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  115,    2, 0x0a /* Public */,
       4,    0,  116,    2, 0x0a /* Public */,
       5,    0,  117,    2, 0x0a /* Public */,
       6,    0,  118,    2, 0x0a /* Public */,
       7,    0,  119,    2, 0x0a /* Public */,
       8,    0,  120,    2, 0x0a /* Public */,
       9,    0,  121,    2, 0x0a /* Public */,
      10,    0,  122,    2, 0x0a /* Public */,
      11,    0,  123,    2, 0x0a /* Public */,
      12,    0,  124,    2, 0x0a /* Public */,
      13,    0,  125,    2, 0x0a /* Public */,
      14,    0,  126,    2, 0x0a /* Public */,
      15,    0,  127,    2, 0x0a /* Public */,
      16,    0,  128,    2, 0x0a /* Public */,
      17,    0,  129,    2, 0x0a /* Public */,
      18,    0,  130,    2, 0x0a /* Public */,
      19,    0,  131,    2, 0x0a /* Public */,
      20,    0,  132,    2, 0x0a /* Public */,
      21,    0,  133,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        case 0: _t->clicked(); break;
        case 1: _t->imageOpen(); break;
        case 2: _t->closeClicked(); break;
        case 3: _t->imageCapture(); break;
        case 4: _t->imageSaveAs(); break;
        case 5: _t->Newfile(); break;
        case 6: _t->version(); break;
        case 7: _t->undo(); break;
        case 8: _t->redo(); break;
        case 9: _t->Screenshot(); break;
        case 10: _t->DrawLine(); break;
        case 11: _t->brushcountfunc(); break;
        case 12: _t->fontsizeup(); break;
        case 13: _t->fontsizedown(); break;
        case 14: _t->colorRedselect(); break;
        case 15: _t->colorBlueselect(); break;
        case 16: _t->colorBlackselect(); break;
        case 17: _t->DrawRect(); break;
        case 18: _t->DrawCir(); break;
        case 19: _t->Erase(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QTProject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QTProject::clicked)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
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
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void QTProject::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
