/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GUI/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mainwindow_t {
    QByteArrayData data[23];
    char stringdata0[364];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainwindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainwindow_t qt_meta_stringdata_mainwindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "mainwindow"
QT_MOC_LITERAL(1, 11, 14), // "data_type_info"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 4), // "type"
QT_MOC_LITERAL(4, 32, 23), // "on_generateList_clicked"
QT_MOC_LITERAL(5, 56, 18), // "on_addList_clicked"
QT_MOC_LITERAL(6, 75, 8), // "add_node"
QT_MOC_LITERAL(7, 84, 6), // "string"
QT_MOC_LITERAL(8, 91, 5), // "input"
QT_MOC_LITERAL(9, 97, 7), // "checked"
QT_MOC_LITERAL(10, 105, 21), // "on_deleteList_clicked"
QT_MOC_LITERAL(11, 127, 19), // "on_sortList_clicked"
QT_MOC_LITERAL(12, 147, 27), // "on_deleteEntireList_clicked"
QT_MOC_LITERAL(13, 175, 29), // "on_generateLiterature_clicked"
QT_MOC_LITERAL(14, 205, 18), // "on_addBook_clicked"
QT_MOC_LITERAL(15, 224, 8), // "add_book"
QT_MOC_LITERAL(16, 233, 4), // "date"
QT_MOC_LITERAL(17, 238, 21), // "on_deleteBook_clicked"
QT_MOC_LITERAL(18, 260, 19), // "on_sortBook_clicked"
QT_MOC_LITERAL(19, 280, 21), // "on_findSeries_clicked"
QT_MOC_LITERAL(20, 302, 11), // "show_series"
QT_MOC_LITERAL(21, 314, 15), // "input_character"
QT_MOC_LITERAL(22, 330, 33) // "on_deleteEntireLiterature_cli..."

    },
    "mainwindow\0data_type_info\0\0type\0"
    "on_generateList_clicked\0on_addList_clicked\0"
    "add_node\0string\0input\0checked\0"
    "on_deleteList_clicked\0on_sortList_clicked\0"
    "on_deleteEntireList_clicked\0"
    "on_generateLiterature_clicked\0"
    "on_addBook_clicked\0add_book\0date\0"
    "on_deleteBook_clicked\0on_sortBook_clicked\0"
    "on_findSeries_clicked\0show_series\0"
    "input_character\0on_deleteEntireLiterature_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainwindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   92,    2, 0x08 /* Private */,
       5,    0,   93,    2, 0x08 /* Private */,
       6,    2,   94,    2, 0x08 /* Private */,
      10,    0,   99,    2, 0x08 /* Private */,
      11,    0,  100,    2, 0x08 /* Private */,
      12,    0,  101,    2, 0x08 /* Private */,
      13,    0,  102,    2, 0x08 /* Private */,
      14,    0,  103,    2, 0x08 /* Private */,
      15,    3,  104,    2, 0x08 /* Private */,
      17,    0,  111,    2, 0x08 /* Private */,
      18,    0,  112,    2, 0x08 /* Private */,
      19,    0,  113,    2, 0x08 /* Private */,
      20,    1,  114,    2, 0x08 /* Private */,
      22,    0,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Bool,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Bool, QMetaType::QDate,    8,    9,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,   21,
    QMetaType::Void,

       0        // eod
};

void mainwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mainwindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->data_type_info((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_generateList_clicked(); break;
        case 2: _t->on_addList_clicked(); break;
        case 3: _t->add_node((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->on_deleteList_clicked(); break;
        case 5: _t->on_sortList_clicked(); break;
        case 6: _t->on_deleteEntireList_clicked(); break;
        case 7: _t->on_generateLiterature_clicked(); break;
        case 8: _t->on_addBook_clicked(); break;
        case 9: _t->add_book((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QDate(*)>(_a[3]))); break;
        case 10: _t->on_deleteBook_clicked(); break;
        case 11: _t->on_sortBook_clicked(); break;
        case 12: _t->on_findSeries_clicked(); break;
        case 13: _t->show_series((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 14: _t->on_deleteEntireLiterature_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (mainwindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mainwindow::data_type_info)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject mainwindow::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_mainwindow.data,
    qt_meta_data_mainwindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mainwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mainwindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int mainwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void mainwindow::data_type_info(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
