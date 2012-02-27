#-------------------------------------------------
#
# Project created by QtCreator 2012-02-21T21:09:42
#
#-------------------------------------------------

QT       += sql testlib gui

#QT       -= gui

TARGET = tst_mordsythteststest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_mordsythteststest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ImageViewer/release/ -lImageViewer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ImageViewer/debug/ -lImageViewer

INCLUDEPATH += $$PWD/../ImageViewer
DEPENDPATH += $$PWD/../ImageViewer

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ImageViewer/release/ImageViewer.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ImageViewer/debug/ImageViewer.lib
