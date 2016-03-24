ROOT=$${PWD}/..
MOC_DIR     = $${ROOT}/temp/moc
OBJECTS_DIR = $${ROOT}/temp/obj
DESTDIR     = $${ROOT}/src/bin
INCLUDEPATH += . $${ROOT}
DEPENDPATH  += . $${ROOT}

#include($${ROOT}/qtsingleapplication/src/qtsingleapplication.pri)

TEMPLATE = app
TARGET = myprogram

QT += widgets 
CONFIG += qt warn_on debug console

# Input
HEADERS += para_tray.h \
					para_menu.h 
SOURCES += main.cpp \
					para_tray.cpp \
					para_menu.cpp 


