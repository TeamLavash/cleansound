#ifndef ICAAUDIOSEPARATOR_H
#define ICAAUDIOSEPARATOR_H

#include "audioseparator.hpp"

class ICAAudioSeparator : public AudioSeparator
{
public:
    ICAAudioSeparator();
    virtual ~ICAAudioSeparator();

    QPair<AudioPtr, AudioPtr> separate(AudioPtr, AudioPtr) override;
};

#endif // ICAAUDIOSEPARATOR_H
