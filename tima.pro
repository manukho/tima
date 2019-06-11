TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += qt
QT     += core gui widgets

LIBS += -lstdc++fs

SOURCES += \
    gui/timeleftitem.cpp \
    tima.cpp \
    gui/mainwindow.cpp \
    gui/borderlayout.cpp \
    todolist/todolist.cpp \
    todolist/todo.cpp \
    calendar/calendar.cpp \
    calendar/appointment.cpp \
    gui/todotable.cpp \
    gui/tododialog.cpp \
    settings.cpp

HEADERS += \
    gui/timeleftitem.h \
    tima.h \
    gui/mainwindow.h \
    gui/borderlayout.h \
    todolist/todolist.h \
    todolist/todo.h \
    calendar/calendar.h \
    calendar/appointment.h \
    gui/todotable.h \
    gui/tododialog.h \
    settings.h

DISTFILES += \
    icons/additem.png \
    icons/addsubitem.png

RESOURCES +=
