#include "wavaudiofile.hpp"
#include <iostream>
#include <fstream>

using namespace std;
WavAudioFile::WavAudioFile(const QString &path) : file(path)
{
    FILE* wavFile = fopen(path.toStdString().c_str(), "rb");
    size_t bytesRead = fread(&wavHeader, 1, sizeof(wav_hdr), wavFile);
    if (bytesRead > 0){
        for(unsigned int i = 0;i<wavHeader.ChunkSize;i += sizeof(sample_t))
               {
            if((i>24)) {
                uint16_t temp;
                fread(&temp,sizeof(temp),1,wavFile);
                //sample_t temp4 = (temp << 16) | temp;
                samples.push_back(temp);
                fread(&temp,sizeof(temp),1,wavFile);
            }
            else {
                sample_t temp;
                fread(&temp,sizeof(temp),1,wavFile);
                samples.push_back(temp);
            }
               }
               /*
                cout << "File is                    :" << filelength << " bytes." << endl;
                cout << "RIFF header                :" << wavHeader.RIFF[0] << wavHeader.RIFF[1] << wavHeader.RIFF[2] << wavHeader.RIFF[3] << endl;
                cout << "WAVE header                :" << wavHeader.WAVE[0] << wavHeader.WAVE[1] << wavHeader.WAVE[2] << wavHeader.WAVE[3] << endl;
                cout << "FMT                        :" << wavHeader.fmt[0] << wavHeader.fmt[1] << wavHeader.fmt[2] << wavHeader.fmt[3] << endl;
                cout << "Data size                  :" << wavHeader.ChunkSize << endl;
                // Display the sampling Rate from the header
                cout << "Sampling Rate              :" << wavHeader.SamplesPerSec << endl;
                cout << "Number of bits used        :" << wavHeader.bitsPerSample << endl;
                cout << "Number of channels         :" << wavHeader.NumOfChan << endl;
                cout << "Number of bytes per second :" << wavHeader.bytesPerSec << endl;
                cout << "Data length                :" << wavHeader.Subchunk2Size << endl;
                cout << "Audio Format               :" << wavHeader.AudioFormat << endl;
                // Audio format 1=PCM,6=mulaw,7=alaw, 257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM
                cout << "Block align                :" << wavHeader.blockAlign << endl;
                cout << "Data string                :" << wavHeader.Subchunk2ID[0] << wavHeader.Subchunk2ID[1] << wavHeader.Subchunk2ID[2] << wavHeader.Subchunk2ID[3] << endl;
                */
}
}

void WavAudioFile::getDiscreteSamples(QVector<sample_t> & s)
{
    s = samples;
}

void WavAudioFile::saveToFile(QString filePath)
{
    FILE* wavFile = fopen(filePath.toStdString().c_str(), "wb");
    int headerSize = sizeof(wav_hdr);
    fwrite(&wavHeader, 1, headerSize, wavFile);
    for(auto it = samples.begin();it != samples.end();it++) {
        fwrite(it,sizeof(sample_t),1,wavFile);
    }
}

