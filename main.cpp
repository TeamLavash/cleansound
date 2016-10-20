#include <QGuiApplication>
#include "qmlconnector.hpp"
#include "wavaudiofile.hpp"
#include <audiofile.hpp>
#include <audioseparator.hpp>
#include <videofile.hpp>
#include <videogetter.hpp>
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QmlConnector myClass;

    return app.exec();
}
