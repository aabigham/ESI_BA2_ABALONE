include(../defaults.pri)

TEMPLATE = lib
TARGET = libcore
DESTDIR = ../lib

SOURCES += \
    Abapro.cpp \
    Board.cpp \
    Cell.cpp \
    Directions.cpp \
    Game.cpp \
    Position.cpp

HEADERS += \
    Abapro.h \
    Board.h \
    Cell.h \
    Color.h \
    Directions.h \
    Game.h \
    Position.h
