#include "wavaudiofile.hpp"
#include <iostream>
#include <fstream>

using namespace std;
WavAudioFile::WavAudioFile(const QString &path) : file(path)
{
    /*
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
    */
    ifstream cbf(path.toStdString().c_str(), ios::binary | ios::in );
    cbf.seekg(0,ios::end);
    long filelength=cbf.tellg();
    cbf.close();
    FILE* wavFile = fopen(path.toStdString().c_str(), "rb");
    int headerSize = sizeof(wav_hdr);
    size_t bytesRead = fread(&wavHeader, 1, headerSize, wavFile);
    if (bytesRead > 0){
     //   uint16_t bytesPerSample = wavHeader.bitsPerSample / 8;      //Number     of bytes per sample
     //   uint64_t numSamples = wavHeader.ChunkSize / bytesPerSample; //How many samples are in the wav file?
        static const uint16_t BUFFER_SIZE = 4096;
        int32_t* buffer = new int32_t[BUFFER_SIZE];
        while ((bytesRead = fread(buffer, sizeof buffer[0], BUFFER_SIZE / (sizeof buffer[0]), wavFile)) > 0)
               {
                    sample_t temp = *(buffer);
                    samples.push_back(temp);
                    cout << "Read " << bytesRead << " bytes." << endl;
               }
        delete [] buffer;

                buffer = nullptr;


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
}
}

void WavAudioFile::getDiscreteSamples(QVector<sample_t> & s)
{
    s = samples;
}

void WavAudioFile::saveToFile(QString filePath)
{
    QFile outFile(filePath);
    outFile.open(QIODevice::WriteOnly);
    int headerSize = sizeof(wav_hdr);
    outFile.write((char*)&wavHeader,headerSize);
    for(auto it = samples.begin();it!=samples.end();it++) {
        outFile.write((char *)(*it),sizeof(sample_t));
    }
    outFile.close();
}

