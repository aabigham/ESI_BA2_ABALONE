include(../defaults.pri)

TEMPLATE = app
CONFIG += console

LIBS += -L../lib -llibcore

SOURCES += \
    DirectionsTest.cpp \
    PositionTest.cpp \
    main.cpp

HEADERS += \
    catch.hpp
