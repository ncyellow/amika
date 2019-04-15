QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testradarclient.cpp

INCLUDEPATH += "./../radare_client"
LIBS += -L"$$OUT_PWD/../LIBS" -lradare_client
