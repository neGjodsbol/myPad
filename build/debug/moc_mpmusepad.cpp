/****************************************************************************
** Meta object code from reading C++ file 'mpmusepad.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mscore/mpmusepad.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mpmusepad.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MusePad_t {
    QByteArrayData data[15];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MusePad_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MusePad_t qt_meta_stringdata_MusePad = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MusePad"
QT_MOC_LITERAL(1, 8, 5), // "mpCmd"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 11), // "const char*"
QT_MOC_LITERAL(4, 27, 8), // "QAction*"
QT_MOC_LITERAL(5, 36, 11), // "setBaseSize"
QT_MOC_LITERAL(6, 48, 6), // "QRect*"
QT_MOC_LITERAL(7, 55, 3), // "cmd"
QT_MOC_LITERAL(8, 59, 12), // "helpBrowser1"
QT_MOC_LITERAL(9, 72, 8), // "tutorial"
QT_MOC_LITERAL(10, 81, 5), // "about"
QT_MOC_LITERAL(11, 87, 7), // "aboutQt"
QT_MOC_LITERAL(12, 95, 13), // "aboutMusicXML"
QT_MOC_LITERAL(13, 109, 9), // "reportBug"
QT_MOC_LITERAL(14, 119, 16) // "switchLayoutMode"

    },
    "MusePad\0mpCmd\0\0const char*\0QAction*\0"
    "setBaseSize\0QRect*\0cmd\0helpBrowser1\0"
    "tutorial\0about\0aboutQt\0aboutMusicXML\0"
    "reportBug\0switchLayoutMode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MusePad[] = {

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
       1,    1,   74,    2, 0x08 /* Private */,
       1,    2,   77,    2, 0x08 /* Private */,
       1,    1,   82,    2, 0x08 /* Private */,
       5,    1,   85,    2, 0x08 /* Private */,
       7,    1,   88,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    1,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void MusePad::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MusePad *_t = static_cast<MusePad *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mpCmd((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 1: _t->mpCmd((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->mpCmd((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 3: _t->setBaseSize((*reinterpret_cast< QRect*(*)>(_a[1]))); break;
        case 4: _t->cmd((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 5: _t->helpBrowser1(); break;
        case 6: _t->tutorial(); break;
        case 7: _t->about(); break;
        case 8: _t->aboutQt(); break;
        case 9: _t->aboutMusicXML(); break;
        case 10: _t->reportBug(); break;
        case 11: _t->switchLayoutMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MusePad::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MusePad.data,
      qt_meta_data_MusePad,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MusePad::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusePad::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MusePad.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "MuseScoreCore"))
        return static_cast< MuseScoreCore*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MusePad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
