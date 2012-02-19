#-------------------------------------------------
#
# Project created by QtCreator 2012-02-19T14:09:44
#
#-------------------------------------------------

QT       += testlib

TARGET = tst_qwe37teststest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_qwe37teststest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ImageViewer/release/ -lImageViewer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ImageViewer/debug/ -lImageViewer
else:symbian: LIBS += -lImageViewer
else:unix: LIBS += -L$$OUT_PWD/../ImageViewer/ -lImageViewer

INCLUDEPATH += $$PWD/../ImageViewer
DEPENDPATH += $$PWD/../ImageViewer

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ImageViewer/release/ImageViewer.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ImageViewer/debug/ImageViewer.lib
else:unix:!symbian: PRE_TARGETDEPS += $$OUT_PWD/../ImageViewer/libImageViewer.a
