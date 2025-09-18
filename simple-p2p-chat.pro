QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

VPATH += cpp/
INCLUDEPATH += h/

SOURCES += \
    aboutme.cpp \
    connect_to_computer.cpp \
    incommingconnection.cpp \
    main.cpp \
    mainwindow.cpp \
    outgoingconnection.cpp

HEADERS += \
    h/aboutme.h \
    h/connect_to_computer.h \
    h/incommingconnection.h \
    h/mainwindow.h \
    h/outgoingconnection.h

FORMS += \
    ui/aboutme.ui \
    ui/connect_to_computer.ui \
    ui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
