#ifndef AUDIOFILE_HPP
#define AUDIOFILE_HPP

#include <QVector>
#include <QString>
#include <cstdint>

typedef int32_t sample_t;

class AudioFile {
public:
    virtual ~AudioFile()
    {
    }

    virtual void getDiscreteSamples(QVector<sample_t> &samples) = 0;
    virtual void setDiscreteSamples(const QVector<sample_t>&) = 0;
    virtual void saveToFile(const QString &filePath) = 0;
};

#endif // AUDIOFILE_HPP
