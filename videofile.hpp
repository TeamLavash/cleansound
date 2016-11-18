#ifndef VIDEOFILE_HPP
#define VIDEOFILE_HPP

#include <QSharedPointer>
#include "audiofile.hpp"

class VideoFile {
public:
    virtual ~VideoFile()
    {
    }

    virtual QSharedPointer<AudioFile> convertToAudio() = 0;
    virtual void loadVideo() = 0;
    virtual const QString &getAudioPath() = 0;
};

#endif // VIDEOFILE_HPP
