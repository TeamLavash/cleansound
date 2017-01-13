#ifndef ICAAUDIOSEPARATOR_H
#define ICAAUDIOSEPARATOR_H

#include <string>
#include "audioseparator.hpp"

class ICAAudioSeparator : public AudioSeparator
{
public:
    ICAAudioSeparator();
    virtual ~ICAAudioSeparator();

    QPair<AudioPtr, AudioPtr> separate(AudioPtr fileA, AudioPtr fileB) override;

private:
    void createSamplesFile(AudioPtr file, const std::string &identifier);
    void readSamplesFile(AudioPtr file, const std::string &identifier);
    static const char *ICA_SCRIPT;
};

#endif // ICAAUDIOSEPARATOR_H
