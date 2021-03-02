include(../defaults.pri)

TEMPLATE = lib
TARGET = libcore
DESTDIR = ../lib

SOURCES += \
    Position.cpp

HEADERS += \
    Board.h \
    Cell.h \
    Color.h \
    Directions.h \
    Game.h \
    Position.h
