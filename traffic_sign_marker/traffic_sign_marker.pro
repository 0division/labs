#-------------------------------------------------
#
# Project created by QtCreator 2017-11-21T22:22:57
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = traffic_sign_marker
TEMPLATE = app


SOURCES += main.cpp\
        userinterface.cpp \
    figureitem.cpp

HEADERS  += userinterface.h \
    figureitem.h

FORMS    += userinterface.ui
