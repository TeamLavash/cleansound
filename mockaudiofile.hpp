#ifndef MOCKAUDIOFILE_H
#define MOCKAUDIOFILE_H

#include "audiofile.hpp"

class MockAudioFile : public AudioFile
{
public:
    MockAudioFile();
    virtual ~MockAudioFile();
    void getDiscreteSamples(QVector<sample_t> &samples) override;
private:
    enum {
        DEFAULT_SAMPLES = 256,
        FILL_VALUE = 42
    };
};

#endif // MOCKAUDIOFILE_H