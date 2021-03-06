#-------------------------------------------------
#
# Project created by QtCreator 2017-03-03T17:29:51
#
#-------------------------------------------------

# ensure one "debug_and_release" in CONFIG, for clarity...
debug_and_release {
    CONFIG -= debug_and_release
    CONFIG += debug_and_release
}
    # ensure one "debug" or "release" in CONFIG so they can be used as
    #   conditionals instead of writing "CONFIG(debug, debug|release)"...
CONFIG(debug, debug|release) {
    CONFIG -= debug release
    CONFIG += debug
}
CONFIG(release, debug|release) {
    CONFIG -= debug release
    CONFIG += release
}

QT -= gui
QT += serialport

TARGET = utils
TEMPLATE = lib

DEFINES += UTILS_LIBRARY

unix {
    target.path = /usr/lib
    INSTALLS += target
}

HEADERS += \
    utils/AutoEnumerate.h \
    utils/sequence.h \
    utils/utils.h \
    utils/utils_global.h \
    graph/Edge.h \
    graph/Graph.h \
    graph/Node.h \
    utils/units.h \
    utils/multiunitswrapper.h \
    utils/electrophoresisresult.h \
    communications/CommandSender.h \
    communications/FileSender.h \
    communications/SerialSender.h \
    utils/memento.h \
    utils/machineflow.h \
    utils/machineflowstringadapter.h \
    utils/utilsjson.h \
    utils/timestampsimulator.h

SOURCES += \
    utils/AutoEnumerate.cpp \
    utils/sequence.cpp \
    utils/utils.cpp \
    communications/FileSender.cpp \
    communications/SerialSender.cpp \
    utils/machineflow.cpp \
    utils/machineflowstringadapter.cpp \
    utils/utilsjson.cpp \
    utils/timestampsimulator.cpp

debug {
    QMAKE_POST_LINK=X:\utils\utils\setDLL.bat $$shell_path($$OUT_PWD/debug) debug
}

!debug {
    QMAKE_POST_LINK=X:\utils\utils\setDLL.bat $$shell_path($$OUT_PWD/release) release
}

INCLUDEPATH += X:\libraries\cereal-1.2.2\include
INCLUDEPATH += X:\libraries\json-2.1.1\src

