#include "mockvideofile.hpp"
#include "mockaudiofile.hpp"

MockVideoFile::MockVideoFile()
{
}

MockVideoFile::~MockVideoFile()
{
}

QSharedPointer<AudioFile> MockVideoFile::convertToAudio()
{
    return QSharedPointer<AudioFile>(new MockAudioFile);
}

void MockVideoFile::loadVideo()
{
}
