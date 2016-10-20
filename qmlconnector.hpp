#ifndef MYCLASS_HPP
#define MYCLASS_HPP

#include <QObject>
class QmlConnector : public QObject
{
    Q_OBJECT
public:
    QmlConnector();
    virtual ~QmlConnector();

public slots:
    void cppSlot(const QString &msg);

private:
    class QQmlApplicationEngine *engine;
    QObject *rootItem;
signals:
    void addFileButtonClicked(int num);
    void startButtonClicked();
};

#endif // MYCLASS_HPP
