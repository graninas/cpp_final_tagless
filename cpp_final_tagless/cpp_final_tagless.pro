QT -= core gui

TARGET = cpp_final_tagless
TEMPLATE = lib
CONFIG += staticlib

QMAKE_CXXFLAGS += -fconcepts
# QMAKE_CXXFLAGS += -fconcepts-ts

HEADERS += \
    ft/ft.h \
    ft/feature_test.h \
    labyrinth/labyrinth.h \
    labyrinth/player.h \
    labyrinth/logger.h \
    labyrinth/prelude.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES +=

SOURCES +=
