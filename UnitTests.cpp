#include <iostream>
#include "UnitTests.hpp"
#include "icaaudioseparator.hpp"
#include "localvideofile.hpp"
#include "mockaudiofile.hpp"
#include "mockaudioseparator.hpp"
#include "mockvideofile.hpp"
#include "mockvideogetter.hpp"
#include "wavaudiofile.hpp"
#include "youtubevideofile.hpp"

UnitTests::UnitTests()
{

}

bool UnitTests::runAll()
{
    return checkMockAudioFile()
            && checkMockAudioSeparator()
            && checkMockVideoFile()
            && checkMockVideoGetter()
            && checkIcaAudioSeparator()
            && checkLocalVideoFile()
            && checkWavAudioFile()
            && checkYoutubeVideoFile();
}

bool UnitTests::checkMockAudioFile()
{
    MockAudioFile audio;
    bool testPassed = checkMockAudioFile(audio);
    if (!testPassed)
        std::cerr << "MockAudioFile test failed!";
    return testPassed;
}

bool UnitTests::checkMockAudioFile(AudioFile &audio)
{
    QVector<sample_t> samples;
    audio.getDiscreteSamples(samples);
    bool testPassed = samples.size() == MockAudioFile::DEFAULT_SAMPLES;
    if (testPassed) {
        for (auto &sample : samples) {
            testPassed = testPassed && (sample == MockAudioFile::FILL_VALUE);
        }
    }
    return testPassed;
}

bool UnitTests::checkMockAudioSeparator()
{
    MockAudioSeparator sep;
    auto res = sep.separate(AudioSeparator::AudioPtr(new MockAudioFile), AudioSeparator::AudioPtr(new MockAudioFile));
    bool testPassed = checkMockAudioFile(*res.first) && checkMockAudioFile(*res.second);
    if (!testPassed)
        std::cerr << "MockAudioSeparator test failed!";
    return testPassed;
}

bool UnitTests::checkMockVideoFile()
{
    MockVideoFile video;
    bool testPassed = checkMockVideoFile(video);
    if (!testPassed)
        std::cerr<< "MockVideoFile test failed!";
    return testPassed;
}

bool UnitTests::checkMockVideoFile(VideoFile &video)
{
    return checkMockAudioFile(*video.convertToAudio());
}

bool UnitTests::checkMockVideoGetter()
{
    MockVideoGetter getter;
    bool testPassed = checkMockVideoFile(*getter.getVideo());
    if (!testPassed)
        std::cerr << "MockVideoGetter test failed!";
    return testPassed;
}

bool UnitTests::checkIcaAudioSeparator()
{
    ICAAudioSeparator sep;
    QString path = "../cleansound/dbg/tst.wav";
    auto res = sep.separate(AudioSeparator::AudioPtr(new WavAudioFile(path)),
                            AudioSeparator::AudioPtr(new WavAudioFile(path)));
    bool testPassed = checkAudioFile(*res.first) && checkAudioFile(*res.second);
    if (!testPassed)
        std::cerr << "IcaAudioSeparator test failed!";
    return testPassed;
}

bool UnitTests::checkLocalVideoFile()
{
    QString path = "../cleansound/dbg/tst.mp4";
    bool testPassed = checkLocalVideoFile(path);
    if (!testPassed)
        std::cerr << "LocalVideoFile test failed!";
    return testPassed;
}

bool UnitTests::checkWavAudioFile()
{
    QString path = "../cleansound/dbg/tst.wav";
    bool testPassed = checkWavAudioFile(path);
    if (!testPassed)
        std::cerr << "WavAudioFile test failed!";
    return testPassed;
}

bool UnitTests::checkWavAudioFile(const QString &name)
{
    WavAudioFile file(name);
    bool testPassed = checkAudioFile(file);
    return testPassed;
}

bool UnitTests::checkAudioFile(AudioFile &file)
{
    QVector<sample_t> samples;
    file.getDiscreteSamples(samples);
    bool testPassed = samples.size() != 0;
    return testPassed;
}

bool UnitTests::checkYoutubeVideoFile()
{
    QString path = "https://www.youtube.com/watch?v=Wch3gJG2GJ4"; // 1 second video
    bool testPassed = checkYoutubeVideoFile(path);
    if (!testPassed)
        std::cerr << "YoutubeVideoFile test failed!";
    return testPassed;
}

bool UnitTests::checkLocalVideoFile(const QString &path)
{
    LocalVideoFile video(path);
    return checkVideoFile(video);
}

bool UnitTests::checkYoutubeVideoFile(const QString &path)
{
    YoutubeVideoFile video(path);
    return checkVideoFile(video);
}

bool UnitTests::checkVideoFile(VideoFile &video)
{
    video.loadVideo();
    auto res = video.convertToAudio();
    QString audioPath = video.getAudioPath();
    bool testPassed = checkWavAudioFile(audioPath) && checkAudioFile(*res);
    return testPassed;
}
