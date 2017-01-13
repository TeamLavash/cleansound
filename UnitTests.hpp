#ifndef UNITTESTS_HPP
#define UNITTESTS_HPP

#include <QString>
#include "audiofile.hpp"
#include "videofile.hpp"

class UnitTests
{
public:
    UnitTests();
    bool runAll();

    bool checkMockAudioFile();
    bool checkMockAudioSeparator();
    bool checkMockVideoFile();
    bool checkMockVideoGetter();
    bool checkIcaAudioSeparator();
    bool checkLocalVideoFile();
    bool checkWavAudioFile();
    bool checkYoutubeVideoFile();
private:
    bool checkMockAudioFile(AudioFile &audio);
    bool checkMockVideoFile(VideoFile &video);
    bool checkWavAudioFile(const QString &name);
    bool checkLocalVideoFile(const QString &path);
    bool checkYoutubeVideoFile(const QString &path);
    bool checkAudioFile(AudioFile &file);
    bool checkVideoFile(VideoFile &video);
};

#endif // UNITTESTS_HPP
