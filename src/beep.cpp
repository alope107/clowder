#include "beep.h"
#include <bn_sound.h>
#include "bn_sound_items.h"
#include <bn_log.h>

void beep::update() {
    beat(game_settings->getCurrentFrame());
    play(beats);
}

int beep::play(bn::unordered_map<int, int, 4> in_beats) {
    for (auto beat : in_beats) {
        BN_LOG(beat_counter);
        if (beat_counter == beat.first) 
            bn::sound::play(bn::sound_items::clap_hi);  
    }

    return 0;
}

int beep::play(bn::vector<int, 4> in_beats) {
    for (auto beat : in_beats) {
        BN_LOG(beat_counter);
        if (beat_counter == beat) 
        {
            // find optimal frame to play
            bn::sound::play(bn::sound_items::clap_hi);  
        }
            
    }

    return 0;
}

int beep::beat(int currFrame){
    if (currFrame % game_bpm == 0)
    {
        if (beat_counter == 4) 
            beat_counter = 1;
        else
            beat_counter +=1;
        BN_LOG(beat_counter);
    }

    return 0;
}