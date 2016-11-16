#-------------------------------------------------
#
# Project created by QtCreator 2016-11-16T09:07:20
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Arenita
TEMPLATE = app


SOURCES += main.cpp\
        principal.cpp \
    acerca.cpp

HEADERS  += principal.h \
    acerca.h

FORMS    += principal.ui \
    acerca.ui

CONFIG += mobility
MOBILITY = 

