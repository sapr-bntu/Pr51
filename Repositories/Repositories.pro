#-------------------------------------------------
#
# Project created by QtCreator 2012-02-18T17:02:58
#
#-------------------------------------------------

QT       -= gui

TARGET = Repositories
TEMPLATE = lib
CONFIG += staticlib

SOURCES += sqlfileinforepository.cpp

HEADERS += sqlfileinforepository.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
