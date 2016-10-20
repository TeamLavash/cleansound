#include <QGuiApplication>
#include "qmlconnector.hpp"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QmlConnector myClass;

    return app.exec();
}
