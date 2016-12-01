#ifndef MYCLASS_HPP
#define MYCLASS_HPP

#include <QObject>
#include <QSound>
#include <QString>

class QmlConnector : public QObject
{
    Q_OBJECT
public:
    QmlConnector();
    virtual ~QmlConnector();

    void setAudio1(const QString &path);
    void setAudio2(const QString &path);

public slots:
    void cppSlot(const QString &msg);

private:
    bool handleLocalLoad(const QString &command);
    bool handleYouTubeLoad(const QString &command);
    bool handlePlay(const QString &command);
    bool handleStart(const QString &command);

    void getAudio(const QString &channel);
    class QQmlApplicationEngine *engine;
    QObject *rootItem;
    QString video1;
    QString video2;
    QString audio1;
    QString audio2;
    QSound *sound1;
    QSound *sound2;
signals:
    void addFileButtonClicked(int num);
    void startButtonClicked();
};

#endif // MYCLASS_HPP
