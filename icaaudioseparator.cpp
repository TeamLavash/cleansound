#include <fstream>
#include "icaaudioseparator.hpp"
#include "wavaudiofile.hpp"
#include "mockaudiofile.hpp"

const char *ICAAudioSeparator::ICA_SCRIPT =
        "import numpy as np"
        "from sklearn.decomposition import FastICA"
        "s1 = np.fromfile(\"~temp_a.bin\", dtype=np.int32, sep=' ')"
        "s2 = np.fromfile(\"~temp_b.bin\", dtype=np.int32, sep=' ')"
        "S = np.c_[s1, s2]"
        "ica = FastICA(n_components=2)"
        "S_ = ica.fit_transform(S)"
        "res = np.transpose(S_)"
        "res[0].tofile(\"~temp_res_a.bin\", sep=' ')"
        "res[1].tofile(\"~temp_res_b.bin\", sep=' ')";

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

void ICAAudioSeparator::readSamplesFile(AudioPtr file, const std::string &identifier)
{
    std::ifstream in("~temp_res_" + identifier + ".bin", std::ios::binary);
    sample_t sample;
    QVector<sample_t> samples;
    while (!in.eof()) {
        in >> sample;
        samples.push_back(sample);
    }
    file->setDiscreteSamples(samples);
}

auto ICAAudioSeparator::separate(AudioPtr, AudioPtr) -> QPair<AudioPtr, AudioPtr>
{
    createSamplesFile(fileA, "A");
    createSamplesFile(fileB, "B");
    std::ofstream out("~temp_scr.py");
    out << ICA_SCRIPT;
    out.close();
    system("python ~temp_scr.py");
    readSamplesFile(fileA, "A");
    readSamplesFile(fileB, "B");
    fileA->saveToFile("resA.wav");
    fileB->saveToFile("resB.wav");
    return qMakePair(AudioPtr(new MockAudioFile), AudioPtr(new MockAudioFile));
}
