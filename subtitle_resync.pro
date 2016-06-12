#-------------------------------------------------
#
# Project created by QtCreator 2016-06-11T11:10:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = subtitle_resync
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    subtitle_file_parser.cpp \
    timestamp_util.cpp

HEADERS  += mainwindow.h \
    subtitle_file_parser.h \
    timestamp_util.h \
    globals.h
