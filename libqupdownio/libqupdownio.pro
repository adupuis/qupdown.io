#-------------------------------------------------
#
# Project created by QtCreator 2013-06-14T10:21:02
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = qupdownio
TEMPLATE = lib

DEFINES += LIBQUPDOWNIO_LIBRARY

LIBS += -lqjson

# Install directory
isEmpty( INSTALLDIR ) {
    INSTALLDIR = /usr/local/lib
    win32:INSTALLDIR = "C:\Program Files\qupdownio\$$TARGET"
    macx:INSTALLDIR = "/Applications"
}

OBJECTS_DIR = ../build
UI_DIR = $$OBJECTS_DIR
MOC_DIR = $$OBJECTS_DIR
RCC_DIR = $$OBJECTS_DIR

SOURCES += libqupdownio.cpp \
    check.cpp \
    checkerror.cpp

HEADERS += libqupdownio.h\
        libqupdownio_global.h \
    check.h \
    checkerror.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
	target.path = $$INSTALLDIR
    }
    INSTALLS += target
}

OTHER_FILES += \
    check.ini \
    checkerror.ini
