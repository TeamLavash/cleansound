#ifndef WAVAUDIOFILE_H
#define WAVAUDIOFILE_H

#include <QVector>
#include <QString>
#include <QFile>
#include <QBitArray>
#include <cstdint>
#include <QSharedPointer>
#include <cstring>
#include "audiofile.hpp"

typedef uint32_t sample_t;
typedef uint8_t header_t;

// Структура, описывающая заголовок WAV файла.

class WavAudioFile : public AudioFile
{
    QVector<sample_t> samples;
    QVector<header_t> header;
    sample_t data_size;
    QString file;
public:
    WavAudioFile(const QString &path);
    void getDiscreteSamples(QVector<sample_t>&) override;
    void setDiscreteSamples(const QVector<sample_t>&) override;
    void saveToFile(const QString &filePath) override;
};

#endif // WAVAUDIOFILE_H
