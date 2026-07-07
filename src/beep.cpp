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
        if (beat_counter == beat && game_settings->getCurrentFrame() == curr_beat_frame +(game_settings->getFramesPerBeat() / 2))
        {
            BN_LOG("played at beat: ", beat_counter);
            BN_LOG("played at frame: ", game_settings->getCurrentFrame());
            bn::sound::play(bn::sound_items::clap_hi); 
        }    
    }

    return 0;
}

int beep::beat(int currFrame){
    if (currFrame % game_fpb == 0)
    {
        if (beat_counter == 4) 
            beat_counter = 1;
        else 
            beat_counter +=1;
        curr_beat_frame = game_settings->getCurrentFrame();
    }

    return 0;
}