#-------------------------------------------------
#
# Project created by QtCreator 2018-05-24T14:34:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MusePad
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    mptoolbutton.cpp \
    mpvoices.cpp \
    mpkeyboard.cpp \
    mpmusepad.cpp \
    palette.cpp \
    mppalettebox.cpp \
    ..\libmscore\musescorecore.cpp \
    shortcut.cpp \
    icons.cpp \
    toolbuttonmenu.cpp \
    mpscreen.cpp \
    mpsettings.cpp


HEADERS += \
    mptoolbutton.h \
    mpvoices.h \
    mpkeyboard.h \
    mptablet.h \
    mpmusepad.h \
    palette.h \
    mppalettebox.h \
    ..\libmscore\musescorecore.h \
    ..\all.h \
    shortcut.h \
    icons.h \
    globals.h \
    preferences.h \
    toolbuttonmenu.h \
    mpscreen.h \
    mpsettings.h

FORMS += \
    mpvoices.ui \
    mpkeyboard.ui \
    mpmusepad.ui \
    mppalettebox.ui \
    mpsettings.ui

RESOURCES += \
    myscore.qrc
