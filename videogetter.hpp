#ifndef VIDEOGETTER_HPP
#define VIDEOGETTER_HPP

#include <QSharedPointer>
#include "videofile.hpp"

class VideoGetter {
public:
    virtual ~VideoGetter()
    {
    }

    virtual QSharedPointer<VideoFile> getVideo() = 0;
};

#endif // VIDEOGETTER_HPP
