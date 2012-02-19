#-------------------------------------------------
#
# Project created by QtCreator 2012-02-19T14:25:55
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_frigikfileinfotest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_frigikfileinfotest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ImageViewer/release/ -lImageViewer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ImageViewer/debug/ -lImageViewer

INCLUDEPATH += $$PWD/../ImageViewer
DEPENDPATH += $$PWD/../ImageViewer

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ImageViewer/release/ImageViewer.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ImageViewer/debug/ImageViewer.lib
