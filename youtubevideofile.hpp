#ifndef YOUTUBEVIDEOFILE_H
#define YOUTUBEVIDEOFILE_H

#include "string"
#include "videofile.hpp"
#include "wavaudiofile.hpp"

class YoutubeVideoFile : public VideoFile
{
    QString video_url;
    QString file_path;
public:
    YoutubeVideoFile(QString);
    QSharedPointer<AudioFile> convertToAudio();
    void loadVideo();
};

#endif // YOUTUBEVIDEOFILE_H
