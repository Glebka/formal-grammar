#-------------------------------------------------
#
# Project created by QtCreator 2012-11-30T09:54:02
#
#-------------------------------------------------

QT       += core gui webkit

TARGET = FormalGrammar
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    highlighter.cpp \
    dependencytree.cpp \
    scanner.cpp \
    matrixbuilder2.cpp \
    searchdialog.cpp \
    gotodialog.cpp \
    replacedialog.cpp \
    matrixviewform.cpp \
    simpleprecedencematrixtablemodel.cpp

HEADERS  += mainwindow.h \
    highlighter.h \
    common.h \
    dependencytree.h \
    scanner.h \
    matrixbuilder2.h \
    searchdialog.h \
    gotodialog.h \
    replacedialog.h \
    matrixviewform.h \
    simpleprecedencematrixtablemodel.h

FORMS    += mainwindow.ui \
    searchdialog.ui \
    gotodialog.ui \
    replacedialog.ui \
    matrixviewform.ui
RC_FILE = myapp.rc

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    jquery.min.js \
    xpathjs.min.js \
    xmlprocessor.html
