#-------------------------------------------------
#
# Project created by QtCreator 2012-02-18T19:34:54
#
#-------------------------------------------------

TARGET = Core
TEMPLATE = lib
CONFIG += staticlib

SOURCES += application.cpp

HEADERS += application.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
