include(../defaults.pri)

TEMPLATE = app
CONFIG += qt

QT += widgets

LIBS += -L../lib -llibcore

SOURCES += \
    GuiController.cpp \
    MainWindow.cpp \
    MarbleWidget.cpp \
    main.cpp

FORMS += \
    MainWindow.ui \
    MarbleWidget.ui

HEADERS += \
    GuiController.h \
    MainWindow.h \
    MarbleWidget.h

RESOURCES += \
    resources.qrc
