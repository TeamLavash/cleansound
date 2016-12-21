#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlProperty>
#include <QDebug>
#include <QFileDialog>
#include <QString>
#include "qmlconnector.hpp"
#include "icaaudioseparator.hpp"

#include <QSound>
#include "localvideofile.hpp"
#include "youtubevideofile.hpp"

QmlConnector::QmlConnector() : QObject(0), sound1(nullptr), sound2(nullptr)
{
    engine = new QQmlApplicationEngine;
    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));
    rootItem = engine->rootObjects().first();
    QObject::connect(rootItem, SIGNAL(qmlSignal(QString)),
                     this, SLOT(cppSlot(QString)));

    QQmlProperty::write(rootItem, "version", QString(GIT_VERSION));
}

QmlConnector::~QmlConnector()
{
    delete sound1;
    delete sound2;
    delete engine;
}

void QmlConnector::setAudio1(const QString &path)
{
    audio1 = path;
}

void QmlConnector::setAudio2(const QString &path)
{
    audio2 = path;
}

void QmlConnector::getAudio(const QString &channel)
{
    QString source = QQmlProperty::read(rootItem, "sourceType").toString();
    QString &audio = channel == "1" ? audio1 : audio2;
    if (source == "YouTube") {
        QString path = QQmlProperty::read(rootItem, "youtubePath" + channel).toString();
        YoutubeVideoFile videoFile(path);
        videoFile.loadVideo();
        audio = videoFile.getAudioPath();
    } else {
        QString path = QQmlProperty::read(rootItem, "localPath" + channel).toString();
        qDebug() << "Opening file " + path + "\n";
        LocalVideoFile videoFile(path);
        videoFile.loadVideo();
        audio = videoFile.getAudioPath();
    }
}

bool QmlConnector::handleLocalLoad(const QString &command)
{
    bool res = false;
    if (command == "ch1") {
        video1 = QQmlProperty::read(rootItem, "localPath1").toString();
        res = true;
    } else if (command == "ch2"){
        video2 = QQmlProperty::read(rootItem, "localPath2").toString();
        res = true;
    }
    return res;
}

bool QmlConnector::handleYouTubeLoad(const QString &command)
{
    bool res = false;
    if (command == "ch1") {
        video1 = QQmlProperty::read(rootItem, "youtubePath1").toString();
        res = true;
    } else if (command == "ch2"){
        video2 = QQmlProperty::read(rootItem, "youtubePath2").toString();
        res = true;
    }
    return res;

}

bool QmlConnector::handlePlay(const QString &command)
{
    bool res = true;
    if (command == "pl1") {
        // Play 1 file
        if (sound1 != nullptr) {
            sound1->stop();
            delete sound1;
            sound1 = nullptr;
        }
        sound1 = new QSound(audio1);
        if (sound1 != nullptr)
            sound1->play();
        res = true;
    } else if (command == "pl2") {
        // Play 2 file
        if (sound2 != nullptr) {
            sound2->stop();
            delete sound2;
            sound2 = nullptr;
        }
        sound2 = new QSound(audio2);
        if (sound2 != nullptr)
            sound2->play();
        res = true;
    }

    return res;
}

bool QmlConnector::handleStart(const QString &command)
{
    if (command != "start")
        return false;

    QString source = QQmlProperty::read(rootItem, "sourceType").toString();

    if (source == "Local") {
        handleLocalLoad("ch1");
        handleLocalLoad("ch2");
        LocalVideoFile videoFile1(video1);
        videoFile1.loadVideo();
        audio1 = videoFile1.getAudioPath();
        LocalVideoFile videoFile2(video2);
        videoFile2.loadVideo();
        audio2 = videoFile2.getAudioPath();
    } else if (source == "YouTube") {
        handleYouTubeLoad("ch1");
        handleYouTubeLoad("ch2");
        YoutubeVideoFile videoFile1(video1);
        videoFile1.loadVideo();
        audio1 = videoFile1.getAudioPath();
        YoutubeVideoFile videoFile2(video2);
        videoFile2.loadVideo();
        audio2 = videoFile2.getAudioPath();
    } else {
        // Exceptional case
    }

    AudioSeparator::AudioPtr a = AudioSeparator::AudioPtr(new WavAudioFile("1.wav"));
    AudioSeparator::AudioPtr b = AudioSeparator::AudioPtr(new WavAudioFile("2.wav"));
    ICAAudioSeparator sep(a, b);
    sep.separate(a, b);
    audio1.prepend("res_");
    audio2.prepend("res_");
    a->saveToFile(audio1);
    b->saveToFile(audio2);
    // TODO write to files and set paths to them
    return true;
}

void QmlConnector::cppSlot(const QString &msg)
{
    // TODOS:
    // 1 - remove code duplication
    // 2 - change slot messages
    // 3 - check if file is valid
    // 4 - refactor
    bool res = handleStart(msg)
            || handlePlay(msg);
    if (!res) {
        // TODO do what?
    }
}
