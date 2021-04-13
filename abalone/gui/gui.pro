include(../defaults.pri)

TEMPLATE = app
CONFIG += qt

QT += widgets

LIBS += -L../lib -llibcore

SOURCES += \
    MainWindow.cpp \
    MarbleWidget.cpp \
    main.cpp

FORMS += \
    MainWindow.ui \
    MarbleWidget.ui

HEADERS += \
    MainWindow.h \
    MarbleWidget.h

RESOURCES += \
    resources.qrc
