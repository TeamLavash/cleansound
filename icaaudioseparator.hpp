#ifndef ICAAUDIOSEPARATOR_H
#define ICAAUDIOSEPARATOR_H

#include <string>
#include "audioseparator.hpp"

class ICAAudioSeparator : public AudioSeparator
{
public:
    ICAAudioSeparator(AudioPtr a, AudioPtr b);
    virtual ~ICAAudioSeparator();

    QPair<AudioPtr, AudioPtr> separate(AudioPtr, AudioPtr) override;

private:
    void createSamplesFile(AudioPtr file, const std::string &identifier);
    AudioPtr fileA;
    AudioPtr fileB;
};

#endif // ICAAUDIOSEPARATOR_H
