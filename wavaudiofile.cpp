#include "wavaudiofile.hpp"
#include <iostream>
#include <fstream>

using namespace std;
WavAudioFile::WavAudioFile(const QString &path) : file(path)
{
    FILE* wavFile = fopen(path.toStdString().c_str(), "rb");
    while (true) {
        header_t temp0;
        header_t temp1;
        header_t temp2;
        header_t temp3;
        fread(&temp0, 1, sizeof(temp0), wavFile);
        if((char)temp0 == 'd') {
            fread(&temp1, 1, sizeof(temp1), wavFile);
            if((char)temp1 == 'a') {
                fread(&temp2, 1, sizeof(temp2), wavFile);
                if((char)temp2 == 't') {
                    fread(&temp3, 1, sizeof(temp3), wavFile);
                    if((char)temp3 == 'a') {
                        fread(&data_size, 1, sizeof(data_size), wavFile);
                        header.push_back(temp0);
                        header.push_back(temp1);
                        header.push_back(temp2);
                        header.push_back(temp3);
                        break;
                    }
                    else {
                        header.push_back(temp0);
                        header.push_back(temp1);
                        header.push_back(temp2);
                        header.push_back(temp3);
                    }
                }
                else {
                    header.push_back(temp0);
                    header.push_back(temp1);
                    header.push_back(temp2);
                }
            }
            else {
                header.push_back(temp0);
                header.push_back(temp1);
            }
        }
        else
        {
            header.push_back(temp0);
        }

    }
    for(unsigned int i = 0;i<data_size;i += sizeof(sample_t))
    {
        uint16_t temp0;
        fread(&temp0,sizeof(temp0),1,wavFile);
        fread(&temp0,sizeof(temp0),1,wavFile);
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

void WavAudioFile::saveToFile(QString filePath)
{
    FILE* wavFile = fopen(filePath.toStdString().c_str(), "wb");
    for(auto it = header.begin();it != header.end();it++) {
        //cout << (char)(*it) << endl;
        fwrite(it,sizeof(header_t),1,wavFile);
    }
    fwrite(&data_size,sizeof(sample_t),1,wavFile);
    for(auto it = samples.begin();it != samples.end();it++) {
        sample_t temp = *it;
        temp = (temp << 16) | temp;
        fwrite(&temp,sizeof(sample_t),1,wavFile);
    }
}

