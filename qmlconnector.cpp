#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlProperty>
#include <QDebug>
#include <QFileDialog>
#include <QString>
#include "qmlconnector.hpp"

#include <QSound>
#include "localvideofile.hpp"

QmlConnector::QmlConnector() : QObject(0)
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
    delete engine;
}

void QmlConnector::cppSlot(const QString &msg)
{
    qDebug() << "Called the C++ slot with message:" << msg;

    if (msg == "3") {
        double value = QQmlProperty::read(rootItem, "progress").toDouble();
        if (value < 1.0) {
            value += 0.05;
            QQmlProperty::write(rootItem, "progress", value);
        }
    }
}
