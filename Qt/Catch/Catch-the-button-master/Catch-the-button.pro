TEMPLATE = app

TARGET = Catch-the-button

QT += widgets

HEADERS += \
    catchbutton.h \
    widget.h

SOURCES += \
    catchbutton.cpp \
    main.cpp \
    widget.cpp

SUBDIRS += \
    ../../../Widget/Widget.pro

DISTFILES +=
