TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += qt
QT     += core gui widgets

LIBS += -lstdc++fs

SOURCES += \
    tima.cpp \
    gui/mainwindow.cpp \
    gui/borderlayout.cpp \

HEADERS += \
    tima.h \
    gui/mainwindow.h \
    gui/borderlayout.h \

DISTFILES += \
    test.xml \
    icons/additem.png \
    icons/addsubitem.png

RESOURCES += \
    resources.qrc
