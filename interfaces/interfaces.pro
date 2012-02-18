#-------------------------------------------------
#
# Project created by QtCreator 2012-02-18T16:48:07
#
#-------------------------------------------------

QT       -= gui

TARGET = interfaces
TEMPLATE = lib
CONFIG += staticlib

SOURCES += ifileinforepository.cpp

HEADERS += ifileinforepository.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
