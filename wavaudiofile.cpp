#include "wavaudiofile.hpp"

WavAudioFile::WavAudioFile(const QString &path) : file(path)
{
    QFile inFile(file);
    if (!inFile.open(QIODevice::ReadOnly)) return;
    inFile.read(reinterpret_cast<char *>(&wavHeader),sizeof(wavHeader));
    QByteArray audioBlock = inFile.readAll();
    sample_t audioArrayLength = audioBlock.length() / 4;
    QSharedPointer <sample_t> audioArray (new sample_t[audioArrayLength]);
    for (unsigned int i = 0;i < audioArrayLength; i++) {
        sample_t temp;
        char &currentBlock = audioBlock.data()[i*4];
        memcpy(&temp, &currentBlock, sizeof(temp));
        samples.push_back(temp);
    }
    inFile.close();
}

void WavAudioFile::getDiscreteSamples(QVector<sample_t> & ourVector)
{
    ourVector = samples;
}


