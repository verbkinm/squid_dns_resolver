TEMPLATE = app
QT+= network
QT-=gui
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt

SOURCES += \
        dns_db.cpp \
        dns_resolver.cpp \
        filereader.cpp \
        filewriter.cpp \
        main.cpp \
        stringparser.cpp

HEADERS += \
    dns_db.h \
    dns_resolver.h \
    filereader.h \
    filewriter.h \
    stringparser.h
