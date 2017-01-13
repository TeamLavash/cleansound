#include <iostream>
#include <fstream>
#include "wavaudiofile.hpp"

using namespace std;

WavAudioFile::WavAudioFile(const QString &path) : file(path)
{
    FILE* wavFile = fopen(path.toStdString().c_str(), "rb");
    const char *overlook = "data";
    uint8_t pos = 0;
    char currentOverlook = overlook[pos];
    while (true) {
        header_t cur;
        fread(&cur, sizeof(cur),1,  wavFile);
        header.push_back(cur);
        if (cur == currentOverlook) {
            currentOverlook = overlook[++pos];
            if (currentOverlook == '\0') {
                fread(&data_size, 1, sizeof(data_size), wavFile);
                break;
            }
        } else if (pos != 0) {
            pos = 0;
            currentOverlook = overlook[pos];
        }
    }

    for(unsigned int i = 0; i < data_size; i += sizeof(sample_t)) {
        uint16_t temp0;
        fread(&temp0, sizeof(temp0), 1, wavFile);
        fread(&temp0, sizeof(temp0), 1, wavFile);
        sample_t temp = temp0;
        samples.push_back(temp);
    }

}

void WavAudioFile::getDiscreteSamples(QVector<sample_t> & s)
{
    s = samples;
}

void WavAudioFile::setDiscreteSamples(const QVector<sample_t> & s)
{
    samples = s;
}

void WavAudioFile::saveToFile(const QString &filePath)
{
    FILE* wavFile = fopen(filePath.toStdString().c_str(), "wb");
    for (auto it = header.begin();it != header.end();it++) {
        fwrite(it, sizeof(header_t), 1, wavFile);
    }
    fwrite(&data_size, sizeof(sample_t), 1, wavFile);
    for (auto it = samples.begin(); it != samples.end(); it++) {
        sample_t temp = *it;
        temp = (temp << 16) | temp;
        fwrite(&temp,sizeof(sample_t),1,wavFile);
    }
}
