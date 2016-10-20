#ifndef AUDIOFILE_HPP
#define AUDIOFILE_HPP

#include <QVector>
#include <cstdint>

typedef uint32_t sample_t;

class AudioFile {
public:
    virtual ~AudioFile()
    {
    }

    virtual void getDiscreteSamples(QVector<sample_t> &samples) = 0;
};

#endif // AUDIOFILE_HPP
