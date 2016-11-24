#include <fstream>
#include "icaaudioseparator.hpp"
#include "wavaudiofile.hpp"
#include "mockaudiofile.hpp"

ICAAudioSeparator::ICAAudioSeparator(AudioPtr a, AudioPtr b) : fileA(a), fileB(b)
{

}

ICAAudioSeparator::~ICAAudioSeparator()
{

}

void ICAAudioSeparator::createSamplesFile(AudioPtr file, const std::string &identifier)
{
    QVector<sample_t> samples;
    file->getDiscreteSamples(samples);
    std::ofstream out("~temp_" + identifier + ".bin", std::ios::binary);
    for (auto sample : samples) {
        out << sample << " ";
    }
    out.close();
}

auto ICAAudioSeparator::separate(AudioPtr, AudioPtr) -> QPair<AudioPtr, AudioPtr>
{
    createSamplesFile(fileA, "A");
    createSamplesFile(fileB, "B");

    return qMakePair(AudioPtr(new MockAudioFile), AudioPtr(new MockAudioFile));
}
