#ifndef YOUTUBEVIDEOFILE_H
#define YOUTUBEVIDEOFILE_H

#include "videofile.hpp"
#include "wavaudiofile.hpp"

class YoutubeVideoFile : public VideoFile
{
public:
    YoutubeVideoFile(QString);
    virtual ~YoutubeVideoFile() = default;
    QSharedPointer<AudioFile> convertToAudio() override;
    void loadVideo() override;
    virtual const QString &getAudioPath() override
    {
        return file_path;
    }
private:
    QString video_url;
    QString file_path;
};

#endif // YOUTUBEVIDEOFILE_H
