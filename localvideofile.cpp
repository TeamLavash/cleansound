#include <cstdlib>
#include <ctime>
#include <exception>
#include "localvideofile.hpp"
#include "wavaudiofile.hpp"

LocalVideoFile::LocalVideoFile(const QString &path) : videoPath(path)
{
}

void LocalVideoFile::loadVideo()
{
    QString tempAudioName = "~tmp_wav_";
    unsigned int randNumb = rand();
    tempAudioName += QString::number(randNumb);
    tempAudioName += ".wav";
#ifdef __linux__
    QString realName = videoPath.remove(0,7);
#elif _WIN32
    QString realName = videoPath.remove(0,8);
#endif
    QString command = "ffmpeg -i " + realName + " -y " + tempAudioName;
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
