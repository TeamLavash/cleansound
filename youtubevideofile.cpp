#include "youtubevideofile.hpp"

YoutubeVideoFile::YoutubeVideoFile(QString url)
{
    video_url = url;
}

QSharedPointer<AudioFile> YoutubeVideoFile::convertToAudio()
{
    return QSharedPointer<AudioFile>(new WavAudioFile(file_path));
}

void YoutubeVideoFile::loadVideo()
{
    QString token;
    for (int i = 0,flag = 0,j = 0;i<video_url.size();i++) {
        if (flag) {
            token += video_url[i];
            j++;
        }
        if (video_url[i] == '=') {
            flag = 1;
        }
    }
    std::string temp = "youtube-dl " + video_url.toStdString() + " --audio-format \"wav\" --extract-audio --id";
    std::system(temp.c_str());
    file_path = "~tmp_" + token + ".wav";
    temp = "rename "  + token.toStdString() + ".wav " + file_path.toStdString();
    std::system(temp.c_str());
}
