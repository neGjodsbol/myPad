/****************************************************************************
** Meta object code from reading C++ file 'mpsettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mscore/mpsettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mpsettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MpSettings_t {
    QByteArrayData data[8];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MpSettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MpSettings_t qt_meta_stringdata_MpSettings = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MpSettings"
QT_MOC_LITERAL(1, 11, 11), // "setBaseSize"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "QRect*"
QT_MOC_LITERAL(4, 31, 23), // "on_smallPButton_clicked"
QT_MOC_LITERAL(5, 55, 7), // "checked"
QT_MOC_LITERAL(6, 63, 24), // "on_mediumPButton_clicked"
QT_MOC_LITERAL(7, 88, 24) // "on_mediumLButton_clicked"

    },
    "MpSettings\0setBaseSize\0\0QRect*\0"
    "on_smallPButton_clicked\0checked\0"
    "on_mediumPButton_clicked\0"
    "on_mediumLButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MpSettings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x08 /* Private */,
       6,    1,   40,    2, 0x08 /* Private */,
       7,    1,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,

       0        // eod
};

void MpSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MpSettings *_t = static_cast<MpSettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setBaseSize((*reinterpret_cast< QRect*(*)>(_a[1]))); break;
        case 1: _t->on_smallPButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_mediumPButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_mediumLButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MpSettings::*_t)(QRect * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MpSettings::setBaseSize)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MpSettings::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MpSettings.data,
      qt_meta_data_MpSettings,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MpSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MpSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MpSettings.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MpSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MpSettings::setBaseSize(QRect * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
