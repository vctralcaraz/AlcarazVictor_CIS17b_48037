QT += core
QT -= gui

CONFIG += c++11

TARGET = CIS17b_Review_1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    prob3table.cpp \
    prob3tableinherited.cpp

HEADERS += \
    prob3table.h \
    prob3tableinherited.h
