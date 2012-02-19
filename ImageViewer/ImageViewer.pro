#-------------------------------------------------
#
# Project created by QtCreator 2012-02-19T13:15:20
#
#-------------------------------------------------

QT       += sql

TARGET = ImageViewer
TEMPLATE = lib
CONFIG += staticlib

SOURCES += application.cpp \
    sqlfileinforepository.cpp \
    ifieinforepositoryfactory.cpp \
    folderservice.cpp \
    fileservice.cpp \
    fileinfo.cpp \
    ifileinforepository.cpp

HEADERS += application.h \
    sqlfileinforepository.h \
    ifileinforepository.h \
    ifieinforepositoryfactory.h \
    folderservice.h \
    fileservice.h \
    fileinfo.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
