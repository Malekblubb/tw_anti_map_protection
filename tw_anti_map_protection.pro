#-------------------------------------------------
#
# Project created by QtCreator 2014-09-12T14:03:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tw_anti_map_protection
TEMPLATE = app
QMAKE_CXX = clang++
QMAKE_CXXFLAGS += -std=c++0x

INCLUDEPATH += external/mlk/include

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.hpp \
    map_parser.hpp

FORMS    += mainwindow.ui
