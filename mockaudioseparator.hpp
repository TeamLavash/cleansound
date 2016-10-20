#ifndef MOCKAUDIOSEPARATOR_H
#define MOCKAUDIOSEPARATOR_H

#include "audioseparator.hpp"

class MockAudioSeparator : public AudioSeparator
{
public:
    MockAudioSeparator();
    virtual ~MockAudioSeparator();

    QPair<AudioPtr, AudioPtr> separate(AudioPtr, AudioPtr) override;
};

#endif // MOCKAUDIOSEPARATOR_H
