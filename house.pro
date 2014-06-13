#-------------------------------------------------
#
# Project created by QtCreator 2014-05-27T16:07:32
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = house
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    housedata.cpp

HEADERS  += mainwindow.h \
    login.h \
    housedata.h \
    connectdatabase.h \
    roomInfo.h

FORMS    += mainwindow.ui \
    login.ui \
    housedata.ui
