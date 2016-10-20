#include <QGuiApplication>
#include "qmlconnector.hpp"

#include <audiofile.hpp>
#include <audioseparator.hpp>
#include <videofile.hpp>
#include <videogetter.hpp>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QmlConnector myClass;
    //
    WavAudioFile testAF("c:\\3211.wav");
    QVector <sample_t> testVector;
    testAF.getDiscreteSamples(testVector);
    qDebug() <<  testVector.length();
    qDebug() <<  testAF.wavHeader.subchunk2Size;
    return app.exec();
}
