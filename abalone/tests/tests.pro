include(../defaults.pri)

TEMPLATE = app
CONFIG += console

LIBS += -L../lib -llibcore

SOURCES += \
    AbaproTest.cpp \
    BoardTest.cpp \
    CellTest.cpp \
    DirectionsTest.cpp \
    GameTest.cpp \
    PositionTest.cpp \
    main.cpp

HEADERS += \
    catch.hpp
