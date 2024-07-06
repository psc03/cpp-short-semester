QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    $$PWD/src/common/    \
    $$PWD/src/app/       \
    $$PWD/src/view/      \
    $$PWD/src/viewmodel/ \
    $$PWD/src/model/     \
    $$PWD/src/window/    \

include($$PWD/src/common/common.pri)
include($$PWD/src/app/app.pri)
include($$PWD/src/view/view.pri)
include($$PWD/src/viewmodel/viewmodel.pri)
include($$PWD/src/model/model.pri)
include($$PWD/src/window/window.pri)

SOURCES += \
    $$PWD/src/main.cpp \
    # $$PWD/src/mainwindow.cpp

# HEADERS += \
    # $$PWD/src/mainwindow.h

FORMS += \
    $$PWD/src/mainwindow.ui

# The icon
RC_ICONS = icon.ico

# Set the title of the program
TARGET = TankTrouble

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pictures/pictures.qrc \
    res.qrc
