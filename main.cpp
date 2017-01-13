#include <cstdlib>
#include <ctime>
#include <QGuiApplication>
#include "qmlconnector.hpp"
#include "wavaudiofile.hpp"
#include "audiofile.hpp"
#include "audioseparator.hpp"
#include "videofile.hpp"
#include "videogetter.hpp"

#ifdef QT_DEBUG
#include <iostream>
#include <cassert>
#include "UnitTests.hpp"
#endif

int main(int argc, char *argv[])
{
#ifdef QT_DEBUG
    UnitTests tests;
    assert(tests.runAll());
    std::cout << "All tests passed!" << std::endl;
#endif

    srand(time(0));

    QGuiApplication app(argc, argv);

    QmlConnector connector;

    return app.exec();
}
