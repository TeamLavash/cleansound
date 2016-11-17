#include <QGuiApplication>
#include "qmlconnector.hpp"
#include "wavaudiofile.hpp"
#include <audiofile.hpp>
#include <audioseparator.hpp>
#include <videofile.hpp>
#include <videogetter.hpp>
#include <youtubevideofile.hpp>
#include <QDebug>

#include "localvideofile.hpp"

int main(int argc, char *argv[])
{
    YoutubeVideoFile hello("https://www.youtube.com/watch?v=op_J1fgK4Pc");
    hello.loadVideo();
    QGuiApplication app(argc, argv);

    return app.exec();
}
