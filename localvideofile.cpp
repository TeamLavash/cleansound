#include <cstdlib>
#include <ctime>
#include <exception>
#include "localvideofile.hpp"
#include "wavaudiofile.hpp"

LocalVideoFile::LocalVideoFile(const QString &path) : videoPath(path)
{
    srand(time(0));
}

void LocalVideoFile::loadVideo()
{
    QString tempAudioName = "~tmp_wav_";
    unsigned int randNumb = rand();
    tempAudioName += QString::number(randNumb);
    tempAudioName += ".wav";
    QString command = "ffmpeg -i " + videoPath + " -y " + tempAudioName;
    int ret = system(command.toStdString().c_str());
    if (ret != 0)
        throw std::exception(); // FIXME

    audioPath = tempAudioName;
}

QSharedPointer<AudioFile> LocalVideoFile::convertToAudio()
{
    if (audioPath == "")
        throw std::exception(); // FIXME
    file = QSharedPointer<AudioFile>(new WavAudioFile(audioPath));
    return file;
}
