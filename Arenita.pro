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
    acerca.cpp \
    iniciarsesion.cpp \
    administrador.cpp \
    administrador/administrar/empresa.cpp \
    administrador/parametro/servidorconfigura.cpp

HEADERS  += principal.h \
    acerca.h \
    iniciarsesion.h \
    administrador.h \
    administrador/administrar/empresa.h \
    administrador/parametro/servidorconfigura.h

FORMS    += principal.ui \
    acerca.ui \
    iniciarsesion.ui \
    administrador.ui \
    administrador/administrar/empresa.ui \
    administrador/parametro/servidorconfigura.ui

CONFIG += mobility
MOBILITY = 

