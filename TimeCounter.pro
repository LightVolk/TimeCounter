#-------------------------------------------------
#
# Project created by QtCreator 2013-01-09T07:13:27
#
#-------------------------------------------------

QT       += core gui sql
QTPLUGIN += qsqlite
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TimeCounter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp

HEADERS  += mainwindow.h \
    database.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    TODO.txt \
    libqsqlite.so
