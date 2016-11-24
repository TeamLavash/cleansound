#include "icaaudioseparator.hpp"
#include "wavaudiofile.hpp"
#include "mockaudiofile.hpp"

ICAAudioSeparator::ICAAudioSeparator()
{

}

ICAAudioSeparator::~ICAAudioSeparator()
{

}

auto ICAAudioSeparator::separate(AudioPtr, AudioPtr) -> QPair<AudioPtr, AudioPtr>
{
    return qMakePair(AudioPtr(new MockAudioFile), AudioPtr(new MockAudioFile));
}
