#include <QGuiApplication>
#include "qmlconnector.hpp"
#include "wavaudiofile.hpp"
#include <audiofile.hpp>
#include <audioseparator.hpp>
#include <videofile.hpp>
#include <videogetter.hpp>
#include <QDebug>

#include "localvideofile.hpp"

int main(int argc, char *argv[])
{
//    QGuiApplication app(argc, argv);

//    QmlConnector myClass;

//    return app.exec();

    qDebug() << "AA\n";

    LocalVideoFile a("shrooms.mp4");
    a.loadVideo();

    auto file = a.convertToAudio();
    return 0;
}
