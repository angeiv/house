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
    housedata.cpp \
    earnestmoney.cpp \
    lessee.cpp \
    housingstatisticsreport.cpp \
    tongji.cpp \
    sentwindow.cpp \
    bookrentals.cpp \
    contract.cpp

HEADERS  += mainwindow.h \
    login.h \
    housedata.h \
    connectdatabase.h \
    roomInfo.h \
    earnestmoney.h \
    lessee.h \
    housingstatisticsreport.h \
    sentwindow.h \
    tongji.h \
    bookrentals.h \
    contract.h

FORMS    += mainwindow.ui \
    login.ui \
    housedata.ui \
    earnestmoney.ui \
    lessee.ui \
    housingstatisticsreport.ui \
    sentwindow.ui \
    tongji.ui \
    bookrentals.ui \
    contract.ui
