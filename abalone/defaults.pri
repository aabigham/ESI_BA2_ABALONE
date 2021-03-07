INCLUDEPATH += $$PWD/metier

SRC_DIR = $$PWD

QMAKE_CXXFLAGS += -Wpedantic -Werror

win32:QMAKE_LFLAGS += -shared

CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++17
