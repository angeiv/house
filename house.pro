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
    #lessee.cpp \
    tongji.cpp \
    sentwindow.cpp \
    bookrentals.cpp \
    contract.cpp \
    rentingdata.cpp \
   # lesseedata.cpp \
    housesatisfaction.cpp \
    replay.cpp \
    earnestmoney.cpp

HEADERS  += mainwindow.h \
    login.h \
    housedata.h \
    connectdatabase.h \
    roomInfo.h \
    #lessee.h \
    sentwindow.h \
    tongji.h \
    bookrentals.h \
    contract.h \
    rentingdata.h \
    #lesseedata.h \
    housesatisfaction.h \
    replay.h \
    earnestmoney.h \
    #le_connectdatabase.h \
    lesseeInfo.h

FORMS    += mainwindow.ui \
    login.ui \
    housedata.ui \
    lessee.ui \
    sentwindow.ui \
    tongji.ui \
    bookrentals.ui \
    contract.ui \
    rentingdata.ui \
    lesseedata.ui \
    housesatisfaction.ui \
    replay.ui \
    earnestmoney.ui

OTHER_FILES += \
    house.pro.user \
    house.pro.user.9760f1a \
    house.pro.user.ba4eb84 \
    housedata.ui.bak \
    house.pro.user.6e6f05e
