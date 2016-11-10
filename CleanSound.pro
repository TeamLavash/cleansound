TEMPLATE = app

QT += core qml quick widgets
CONFIG += c++11

SOURCES += main.cpp \
    qmlconnector.cpp \
    mockaudiofile.cpp \
    mockvideofile.cpp \
    mockvideogetter.cpp \
    mockaudioseparator.cpp \
    wavaudiofile.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

GIT_VERSION = $$system(git --always --tags)

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
    wavaudiofile.hpp
