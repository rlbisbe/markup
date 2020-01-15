CONFIG += warn_on qmltestcase

TEMPLATE = app

DISTFILES +=

SOURCES += \
    ../markup/wordcounter.cpp \
    main.cpp \
    testmarkdownparser.cpp \
    testwordcounter.cpp

INCDIR = ../markup
INCLUDEPATH += $$INCDIR
HEADERS += $$INCDIR/markdownparser.h \
    ../markup/wordcounter.h \
    testmarkdownparser.h \
    testwordcounter.h
SOURCES += $$INCDIR/markdownparser.cpp
