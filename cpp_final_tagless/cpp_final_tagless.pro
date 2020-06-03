QT -= core gui

TARGET = cpp_final_tagless
TEMPLATE = lib
CONFIG += staticlib

#CONFIG += c++2a

# QMAKE_CXXFLAGS += -std=c++2a
 QMAKE_CXXFLAGS += -fconcepts

# SOURCES += \

HEADERS += \
    ft/types.h \
    ft/ft.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES +=
