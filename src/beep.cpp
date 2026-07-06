#include "beep.h"
#include <bn_sound.h>
#include "bn_sound_items.h"
#include <bn_log.h>

int beep::play(int currFrame){
    // play a sound
    if (currFrame % 60 == 0)
    {
        bn::sound::play(bn::sound_items::clap_hi);
        BN_LOG(currFrame);
        return 1;
    }
    return 0;
}