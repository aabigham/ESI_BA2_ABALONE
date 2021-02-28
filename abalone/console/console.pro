include(../defaults.pri)

TEMPLATE = app
CONFIG += console

LIBS += -L../lib -llibcore

SOURCES += \
        main.cpp

HEADERS += \
    ConsoleView.h \
    Controller.h \
    View.h
