#-------------------------------------------------
#
# Project created by QtCreator 2014-10-02T22:45:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tagreader
TEMPLATE = app


SOURCES += main.cpp\
        tagreader.cpp


HEADERS  += tagreader.h

FORMS    += tagreader.ui


LIBS += -L$$PWD/id3lib-3.8.3binaries/release/ -lid3lib
LIBS += -L$$PWD/id3lib-3.8.3binaries/debug/ -lid3lib

INCLUDEPATH += $$PWD/id3lib-3.8.3binaries
DEPENDPATH += $$PWD/id3lib-3.8.3binaries

OTHER_FILES += \
    BGM_Ban_Ramuh.mp3
