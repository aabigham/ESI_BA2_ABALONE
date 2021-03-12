include(../defaults.pri)

TEMPLATE = app
CONFIG += console

LIBS += -L../lib -llibcore

SOURCES += \
    BoardTest.cpp \
    CellTest.cpp \
    DirectionsTest.cpp \
    PositionTest.cpp \
    main.cpp

HEADERS += \
    catch.hpp
