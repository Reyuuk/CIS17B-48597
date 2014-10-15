#-------------------------------------------------
#
# Project created by QtCreator 2014-10-11T12:09:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MusicOrganizer
TEMPLATE = app


SOURCES += main.cpp\
        musicorganizer.cpp

HEADERS  += musicorganizer.h

FORMS    += musicorganizer.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/id3lib-3.8.3binaries/release/ -lid3lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/id3lib-3.8.3binaries/debug/ -lid3lib
else:unix: LIBS += -L$$PWD/id3lib-3.8.3binaries/ -lid3lib

INCLUDEPATH += $$PWD/id3lib-3.8.3binaries
DEPENDPATH += $$PWD/id3lib-3.8.3binaries
