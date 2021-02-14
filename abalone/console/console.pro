include(../defaults.pri)

TEMPLATE = app
CONFIG += console

LIBS += -L../lib -llibcore

SOURCES += \
        main.cpp

HEADERS += \
    Controller.h \
    View.h
