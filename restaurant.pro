QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    admin.cpp \
    adminpanel.cpp \
    customcheckbox.cpp \
    dish.cpp \
    group_admin.cpp \
    group_waiter.cpp \
    history.cpp \
    items_order.cpp \
    login_admin.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    orders.cpp \
    staffvirt.cpp \
    table.cpp \
    waiter.cpp\
    group.cpp\
    result_order.cpp


HEADERS += \
    admin.h \
    adminpanel.h \
    customcheckbox.h \
    dish.h \
    group.h \
    group_admin.h \
    group_waiter.h \
    history.h \
    items_order.h \
    login_admin.h \
    mainwindow.h \
    menu.h \
    orders.h \
    result_order.h \
    staffvirt.h \
    table.h \
    waiter.h \
    result_order.h


FORMS += \
    adminpanel.ui \
    history.ui \
    login_admin.ui \
    mainwindow.ui \
    result_order.ui

TRANSLATIONS += \
    restaurant_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
