#include "mockaudiofile.hpp"

MockAudioFile::MockAudioFile()
{

}

MockAudioFile::~MockAudioFile()
{
}

void MockAudioFile::getDiscreteSamples(QVector<sample_t> &samples)
{
    samples.resize(DEFAULT_SAMPLES);
    samples.fill(FILL_VALUE);
}
