#-------------------------------------------------
#
# Project created by QtCreator 2016-06-29T21:17:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = paint
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ./interfaces/shape.cpp \
    canvas.cpp \
    ./shapes/line.cpp \
    ./shapes/rectangle.cpp \
    ./shapes/circle.cpp \
    dialogbrushwidth.cpp \
    ./shapes/brush.cpp \
    drawassistant.cpp \
    interfaces/idrawable.cpp

HEADERS  += mainwindow.h \
    ./interfaces/idrawable.h \
    ./interfaces/shape.h \
    canvas.h \
    ./shapes/line.h \
    ./shapes/rectangle.h \
    ./shapes/circle.h \
    dialogbrushwidth.h \
    ./shapes/brush.h \
    drawassistant.h

FORMS    += mainwindow.ui \
    canvas.ui \
    dialogbrushwidth.ui

RESOURCES += \
    res.qrc
