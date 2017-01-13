#include <cstdlib>
#include <ctime>
#include <QGuiApplication>
#include "qmlconnector.hpp"
#include "wavaudiofile.hpp"
#include "audiofile.hpp"
#include "audioseparator.hpp"
#include "videofile.hpp"
#include "videogetter.hpp"

int main(int argc, char *argv[])
{
    srand(time(0));

    QGuiApplication app(argc, argv);

    QmlConnector connector;

    return app.exec();
}
