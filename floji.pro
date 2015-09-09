#-------------------------------------------------
#
# Project created by QtCreator 2015-08-16T13:38:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = floji
TEMPLATE = app

CONFIG += c++14

SOURCES += main.cpp\
           mainwindow.cpp \
           scene.cpp \
           view.cpp \

HEADERS  += mainwindow.h \
            scene.h \
            view.h \
            identifiers.h

FORMS    += mainwindow.ui

RESOURCES = icons/icons.qrc
