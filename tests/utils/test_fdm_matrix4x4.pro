QT += testlib
QT -= gui

################################################################################

CONFIG += console
CONFIG -= app_bundle
CONFIG += fdm_test

TEMPLATE = app

################################################################################

TARGET = test_fdm_matrix4x4

################################################################################

DEFINES += QT_DEPRECATED_WARNINGS

################################################################################

INCLUDEPATH += . ../..

win32: INCLUDEPATH += \
    $(OSG_ROOT)/include/ \
    $(OSG_ROOT)/include/libxml2

unix: INCLUDEPATH += \
    /usr/include/libxml2

################################################################################

win32: LIBS += \
    -L$(OSG_ROOT)/lib \
    -llibxml2

unix: LIBS += \
    -L/lib \
    -L/usr/lib \
    -lxml2

################################################################################

include(../../fdm/fdm.pri)

################################################################################

SOURCES += \
    test_fdm_matrix4x4.cpp

################################################################################

DEFINES += SRCDIR=\\\"$$PWD/\\\"
