TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        tguirlande.cpp \
        toctet.cpp

HEADERS += \
    tguirlande.h \
    toctet.h \
    pario.h \
    client_tcp.h \
    I2c.h \
    pcf8574.h

LIBS += -L$$PWD -lpario
