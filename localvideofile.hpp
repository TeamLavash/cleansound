#ifndef LOCALVIDEOFILE_H
#define LOCALVIDEOFILE_H

#include <QString>
#include "videofile.hpp"

class LocalVideoFile : public VideoFile
{
public:
    LocalVideoFile(const QString &path);

    virtual QSharedPointer<AudioFile> convertToAudio() override;
    virtual void loadVideo() override;

    virtual const QString &getAudioPath() override
    {
        return audioPath;
    }

private:

    QString videoPath;
    QString audioPath;
    QSharedPointer<AudioFile> file;
};

#endif // LOCALVIDEOFILE_H
