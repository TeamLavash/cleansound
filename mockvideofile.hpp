#ifndef MOCKVIDEOFILE_H
#define MOCKVIDEOFILE_H

#include <videofile.hpp>

class MockVideoFile : public VideoFile
{
public:
    MockVideoFile();
    virtual ~MockVideoFile();

    QSharedPointer<AudioFile> convertToAudio() override;
};

#endif // MOCKVIDEOFILE_H
