#-------------------------------------------------
#
# Project created by QtCreator 2012-02-18T16:22:13
#
#-------------------------------------------------

QT       -= gui

TARGET = model
TEMPLATE = lib
CONFIG += staticlib

SOURCES += fileinfo.cpp

HEADERS += fileinfo.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
