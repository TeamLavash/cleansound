#ifndef AUDIOSEPARATOR_HPP
#define AUDIOSEPARATOR_HPP

#include <QPair>
#include <QSharedPointer>
#include "audiofile.hpp"

class AudioSeparator {
public:
    using AudioPtr = QSharedPointer<AudioFile>;
    virtual ~AudioSeparator()
    {
    }

    virtual QPair<AudioPtr, AudioPtr> separate(AudioPtr mixedA, AudioPtr mixedB) = 0;
};

#endif // AUDIOSEPARATOR_HPP
