#ifndef MOCKVIDEOGETTER_H
#define MOCKVIDEOGETTER_H

#include "videogetter.hpp"

class MockVideoGetter : public VideoGetter
{
public:
    MockVideoGetter();
    virtual ~MockVideoGetter();

    QSharedPointer<VideoFile> getVideo() override;
};

#endif // MOCKVIDEOGETTER_H
