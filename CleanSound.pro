TEMPLATE = app

QT += core qml quick widgets multimedia
CONFIG += c++11

SOURCES += main.cpp \
    qmlconnector.cpp \
    mockaudiofile.cpp \
    mockvideofile.cpp \
    mockvideogetter.cpp \
    mockaudioseparator.cpp \
    wavaudiofile.cpp \
    localvideofile.cpp \
    youtubevideofile.cpp \
    icaaudioseparator.cpp \
    UnitTests.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

GIT_VERSION = $$system(git describe --always)

DEFINES += GIT_VERSION=\\\"$$GIT_VERSION\\\"

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    qmlconnector.hpp \
    audiofile.hpp \
    videogetter.hpp \
    videofile.hpp \
    audioseparator.hpp \
    mockaudiofile.hpp \
    mockvideofile.hpp \
    mockvideogetter.hpp \
    mockaudioseparator.hpp \
    wavaudiofile.hpp \
    localvideofile.hpp \
    youtubevideofile.hpp \
    icaaudioseparator.hpp \
    UnitTests.hpp
