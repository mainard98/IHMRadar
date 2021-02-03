QT += core gui serialport
QT += charts
QT += xml
QT += widgets network
QT += datavisualization


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Serial.cpp \
    config.cpp \
    ihm6843.cpp \
    inifile.cpp \
    inputdialog.cpp \
    json.cpp \
    lecture.cpp \
    lecturefile.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    sockettcp.cpp \
    txt.cpp \
    xml.cpp

HEADERS += \
    Serial.h \
    config.h \
    ihm6843.h \
    inifile.h \
    inputdialog.h \
    json.h \
    lecture.h \
    lecturefile.h \
    mainwindow.h \
    qcustomplot.h \
    sockettcp.h \
    txt.h \
    xml.h

FORMS += \
    ihm6843.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

target.path = $$[QT_INSTALL_EXAMPLES]/charts/callout
INSTALLS += target
