include(../defaults.pri)

TEMPLATE = app
CONFIG += console

LIBS += -L../lib -llibcore

SOURCES += \
        ConsoleView.cpp \
        View.cpp \
        main.cpp

HEADERS += \
    ConsoleView.h \
    Controller.h \
    View.h
