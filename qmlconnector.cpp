#include <QDebug>
#include "qmlconnector.hpp"

void QmlConnector::cppSlot(const QString &msg)
{
    qDebug() << "Called the C++ slot with message:" << msg;
}
