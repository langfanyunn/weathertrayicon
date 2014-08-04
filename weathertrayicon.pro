#-------------------------------------------------
#
# Project created by QtCreator 2014-07-25T21:14:59
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = weathertrayicon
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11
SOURCES += main.cpp \
    tray.cpp \
    widget.cpp

HEADERS  += \
    tray.h \
    widget.h

RESOURCES += \
    image.qrc

FORMS += \
    widget.ui
