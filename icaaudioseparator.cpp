#include <fstream>
#include "icaaudioseparator.hpp"
#include "wavaudiofile.hpp"
#include "mockaudiofile.hpp"

const char *ICAAudioSeparator::ICA_SCRIPT =
        "import numpy as np\n"
        "from sklearn.decomposition import FastICA\n"
        "s1 = np.fromfile(\"~temp_A.bin\", dtype=np.int32, sep=' ')\n"
        "s2 = np.fromfile(\"~temp_B.bin\", dtype=np.int32, sep=' ')\n"
        "S = np.c_[s1, s2]\n"
        "ica = FastICA(n_components=2)\n"
        "S_ = ica.fit_transform(S) \n"
        "S_ = S_ / S_.std(axis=0)\n"
        "res = np.transpose(S_)\n"
        "res[0].tofile(\"~temp_res_A.bin\", sep=' ')\n"
        "res[1].tofile(\"~temp_res_B.bin\", sep=' ')\n";

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
    system("python3 ~temp_scr.py");
//    readSamplesFile(fileA, "A");
//    readSamplesFile(fileB, "B");
//    fileA->saveToFile("resA.wav");
//    fileB->saveToFile("resB.wav");
    return qMakePair(AudioPtr(new MockAudioFile), AudioPtr(new MockAudioFile));
}
