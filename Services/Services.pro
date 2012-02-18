#-------------------------------------------------
#
# Project created by QtCreator 2012-02-18T17:32:39
#
#-------------------------------------------------

QT       -= gui

TARGET = Services
TEMPLATE = lib
CONFIG += staticlib

SOURCES += fileservice.cpp \
    folderservice.cpp

HEADERS += fileservice.h \
    folderservice.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
