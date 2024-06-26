QT       += core gui remoteobjects

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    rpcbridge.cpp \
    servicewindow.cpp

HEADERS += \
    general.h \
    rpcbridge \
    rpcbridge.h \
    servicewindow.h

FORMS += \
    servicewindow.ui

INCLUDEPATH += ../RPCs
DEPENDPATH += ../RPCs

REPC_SOURCE += ../RPCs/rpcbridge.rep

DISTFILES += ../RPCs/rpcbridge.rep
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
