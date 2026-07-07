#include "beep.h"
#include <bn_sound.h>
#include "bn_sound_items.h"
#include <bn_log.h>

void beep::update() {
    beat(game_settings->getCurrentFrame());
    play();
}

int beep::play() {
    measure curr_measure = m_song[measure_counter];
    if (play_beat(curr_measure, beat_counter) && game_settings->getCurrentFrame() == curr_beat_frame) {
        BN_LOG("played at beat: ", beat_counter);
        BN_LOG("played at frame: ", game_settings->getCurrentFrame());
        bn::sound::play(bn::sound_items::clap_hi); 
    }

    // for (auto measures : m_song) {
    //     //{x, y, z, a, b, c}



    //     if ((beat_counter) == measures && game_settings->getCurrentFrame() == curr_beat_frame ) // second half is so it doesn't play for the entire time
    //     {
    //         BN_LOG("played at beat: ", beat_counter);
    //         BN_LOG("played at frame: ", game_settings->getCurrentFrame());
    //         bn::sound::play(bn::sound_items::clap_hi); 
    //     }    
    // }

    return 0;
}

int beep::beat(int currFrame){
    if (currFrame % (game_fpb/4) == 0)
    {
        if (beat_counter == 15) 
        {
            beat_counter = 0;
            measure_counter += 1;
        }
        else 
        {
            beat_counter +=1;
        }
        curr_beat_frame = game_settings->getCurrentFrame();
        BN_LOG(beat_counter);

        if (measure_counter == m_song.size() ) {
            measure_counter = 0;
        }
    }
    return 0;
}