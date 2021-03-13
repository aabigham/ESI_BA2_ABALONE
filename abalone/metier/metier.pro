include(../defaults.pri)

TEMPLATE = lib
TARGET = libcore
DESTDIR = ../lib

SOURCES += \
    Board.cpp \
    Cell.cpp \
    Game.cpp \
    Position.cpp

HEADERS += \
    Board.h \
    Cell.h \
    Color.h \
    Directions.h \
    Game.h \
    Position.h
