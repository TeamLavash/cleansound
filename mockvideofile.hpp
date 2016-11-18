#ifndef MOCKVIDEOFILE_H
#define MOCKVIDEOFILE_H

#include <videofile.hpp>

class MockVideoFile : public VideoFile
{
private:
    QString path = "";
public:
    MockVideoFile();
    virtual ~MockVideoFile();

    QSharedPointer<AudioFile> convertToAudio() override;
    void loadVideo() override;
    virtual const QString &getAudioPath() override
    {
        return path;
    }

};

#endif // MOCKVIDEOFILE_H
