#-------------------------------------------------
#
# Project created by QtCreator 2019-04-14T22:56:17
#
#-------------------------------------------------

QT       -= gui

CONFIG += c++17
TARGET = radare_client
TEMPLATE = lib

DEFINES += RADARE_CLIENT_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        radareclient.cpp

HEADERS += \
        radareclient.h \
        radare_client_global.h 

unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += /usr/include/libr

LIBS += \
    -lr_core \
    -lr_config \
    -lr_cons \
    -lr_io \
    -lr_util \
    -lr_flag \
    -lr_asm \
    -lr_debug \
    -lr_hash \
    -lr_bin \
    -lr_lang \
    -lr_anal \
    -lr_parse \
    -lr_bp \
    -lr_egg \
    -lr_reg \
    -lr_search \
    -lr_syscall \
    -lr_socket \
    -lr_fs \
    -lr_magic \
    -lr_crypto
