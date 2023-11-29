QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    caredit.cpp \
    carremove.cpp \
    carsearch.cpp \
    carwindow.cpp \
    customeredit.cpp \
    customerremove.cpp \
    customersearch.cpp \
    customerwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    removerental.cpp \
    rentalwindow.cpp \
    sql.cpp

HEADERS += \
    caredit.h \
    carremove.h \
    carsearch.h \
    carwindow.h \
    customeredit.h \
    customerremove.h \
    customersearch.h \
    customerwindow.h \
    mainwindow.h \
    removerental.h \
    rentalwindow.h \
    sql.h

FORMS += \
    caredit.ui \
    carremove.ui \
    carsearch.ui \
    carwindow.ui \
    customeredit.ui \
    customerremove.ui \
    customersearch.ui \
    customerwindow.ui \
    mainwindow.ui \
    removerental.ui \
    rentalwindow.ui

RESOURCES += \
    pictures.qrc \
    qdarkstyle/dark/style.qrc\
    qdarkstyle/light/style.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
