#-------------------------------------------------
#
# Project created by QtCreator 2014-09-29T18:23:09
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Network
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client.cpp \
    server.cpp

HEADERS  += mainwindow.h \
    client.h \
    server.h

FORMS    += mainwindow.ui
