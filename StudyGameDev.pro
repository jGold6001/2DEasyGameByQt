#-------------------------------------------------
#
# Project created by QtCreator 2016-04-03T19:44:36
#
#-------------------------------------------------

QT       += core gui \
         multimedia





greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StudyGameDev
TEMPLATE = app


SOURCES += main.cpp \
    Bullet.cpp \
    Enemy.cpp \
    Player.cpp \
    Game.cpp \
    Score.cpp \
    Health.cpp

HEADERS  += \
    Bullet.h \
    Enemy.h \
    Player.h \
    using_libs.h \
    Game.h \
    Score.h \
    Health.h

FORMS    +=

RESOURCES += \
    resourcefiles.qrc

