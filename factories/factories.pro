#-------------------------------------------------
#
# Project created by QtCreator 2012-02-18T17:06:00
#
#-------------------------------------------------

QT       -= gui

TARGET = factories
TEMPLATE = lib
CONFIG += staticlib

SOURCES += ifieinforepositoryfactory.cpp

HEADERS += ifieinforepositoryfactory.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
