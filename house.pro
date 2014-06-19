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
    tongji.cpp \
    sentwindow.cpp \
    bookrentals.cpp \
    contract.cpp \
    rentingdata.cpp \
    housesatisfaction.cpp \
    lessee.cpp \
    lesseedata.cpp \
    depoist.cpp \
    repaymanagement.cpp \
    updatarepay.cpp

HEADERS  += mainwindow.h \
    login.h \
    housedata.h \
    connectdatabase.h \
    roomInfo.h \
    sentwindow.h \
    tongji.h \
    bookrentals.h \
    contract.h \
    rentingdata.h \
    housesatisfaction.h \
    housesa_conn.h \
    houseInfo.h \
    lessee.h \
    customerinfo.h \
    rentInfo.h \
    rentInfoQuery.h \
    le_connectdatabase.h \
    le_customer.h \
    lesseedata.h \
    lesseeInfo.h \
    connect_wanted.h \
    wantedinfo.h \
    checkUser.h \
    userInfo.h \
    lesseesa_conn.h \
    connect_book.h \
    connect_contract.h \
    connect_depoist.h \
    connect_repay.h \
    contractinfo.h \
    depoist.h \
    repaymanagement.h \
    updatarepay.h \
    re_depositInfo.h \
    replay_conn.h \
    customer.h \
    wantedsati.h


FORMS    += mainwindow.ui \
    login.ui \
    housedata.ui \
    lessee.ui \
    sentwindow.ui \
    tongji.ui \
    bookrentals.ui \
    contract.ui \
    rentingdata.ui \
    housesatisfaction.ui \
    lesseedata.ui \
    depoist.ui \
    repaymanagement.ui \
    updatarepay.ui \
    replay.ui

OTHER_FILES += \
    .gitattributes \
    .gitignore \
    README.md \
    house.pro.user 
