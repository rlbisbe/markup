CONFIG += warn_on qmltestcase

TEMPLATE = app

DISTFILES +=

SOURCES += \
    main.cpp \
    testmarkdownparser.cpp

INCDIR = ../markup
INCLUDEPATH += $$INCDIR
HEADERS += $$INCDIR/markdownparser.h \
    testmarkdownparser.h
SOURCES += $$INCDIR/markdownparser.cpp
