INCLUDEPATH += $$PWD/metier

SRC_DIR = $$PWD

QMAKE_CXXFLAGS += -Wpedantic et -Werror

CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++17
