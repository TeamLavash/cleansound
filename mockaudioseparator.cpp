#include "mockaudioseparator.hpp"
#include "mockaudiofile.hpp"

MockAudioSeparator::MockAudioSeparator()
{
}

MockAudioSeparator::~MockAudioSeparator()
{
}

auto MockAudioSeparator::separate(AudioPtr, AudioPtr) -> QPair<AudioPtr, AudioPtr>
{
    return qMakePair(AudioPtr(new MockAudioFile), AudioPtr(new MockAudioFile));
}
