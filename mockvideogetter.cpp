#include "mockvideogetter.hpp"
#include "mockvideofile.hpp"

MockVideoGetter::MockVideoGetter()
{

}

MockVideoGetter::~MockVideoGetter()
{

}

QSharedPointer<VideoFile> MockVideoGetter::getVideo()
{
    return QSharedPointer<VideoFile>(new MockVideoFile);
}
