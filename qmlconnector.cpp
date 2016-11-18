#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlProperty>
#include <QDebug>
#include <QFileDialog>
#include <QString>
#include "qmlconnector.hpp"

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
//sourceType
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

void QmlConnector::cppSlot(const QString &msg)
{
    // TODOS:
    // 1 - remove code duplication
    // 2 - change slot messages
    // 3 - check if file is valid
    // 4 - refactor
    if (msg == "ch1") {
        QString videoName = QQmlProperty::read(rootItem, "localPath1").toString();
        LocalVideoFile videoFile(videoName);
        videoFile.loadVideo();
        audio1 = videoFile.getAudioPath();
    } else if (msg == "ch2"){
        QString videoName = QQmlProperty::read(rootItem, "localPath2").toString();
        LocalVideoFile videoFile(videoName);
        videoFile.loadVideo();
        audio2 = videoFile.getAudioPath();
    } else if (msg == "start") {
        double value = QQmlProperty::read(rootItem, "progress").toDouble();
        if (value < 1.0) {
            value += 0.6;
            QQmlProperty::write(rootItem, "progress", value);
        } else {
            bool finished = true;
            QQmlProperty::write(rootItem, "finished", finished);
        }
    } else if (msg == "pl1") {
        // Play 1 file
        if (sound1 != nullptr) {
            sound1->stop();
            delete sound1;
            sound1 = nullptr;
        }
        sound1 = new QSound(audio1);
        if (sound1 != nullptr)
            sound1->play();
    } else if (msg == "pl2") {
        // Play 2 file
        if (sound2 != nullptr) {
            sound2->stop();
            delete sound2;
            sound2 = nullptr;
        }
        sound2 = new QSound(audio2);
        if (sound2 != nullptr)
            sound2->play();
    } else if (msg == "pl1") {
        // Stop 1 file
        if (sound1 != nullptr)
            sound1->stop();
    } else if (msg == "pl2") {
        // Stop 2 file
        if (sound2 != nullptr)
            sound2->stop();
    }
}
