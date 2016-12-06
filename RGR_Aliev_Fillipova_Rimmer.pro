#-------------------------------------------------
#
# Project created by QtCreator 2016-11-27T20:41:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RGR_Aliev_Fillipova_Rimmer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    market.cpp \
    newgame.cpp \
    load.cpp \
    save.cpp \
    player.cpp

HEADERS  += mainwindow.h \
    market.h \
    newgame.h \
    load.h \
    save.h \
    player.h \
    dataops.h

FORMS    += mainwindow.ui \
    market.ui \
    newgame.ui \
    load.ui \
    save.ui
