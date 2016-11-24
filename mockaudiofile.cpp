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

void MockAudioFile::setDiscreteSamples(const QVector<sample_t>&)
{
    // Do nothing
}

void MockAudioFile::saveToFile(const QString &)
{
    // Do nothing
}
