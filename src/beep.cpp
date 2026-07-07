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
        bn::sound::play(bn::sound_items::clap_hi); 
        hit_frames.push_back(curr_beat_frame);
    }
    return 0;
}

int beep::beat(int currFrame){
    if (currFrame % (game_fpb/4) == 0)
    {
        if (beat_counter == 15) 
        {
            beat_counter = 0;
            measure_counter += 1;
            for (auto elem : hit_frames)
                BN_LOG(elem);
            hit_frames.clear();
        }
        else 
        {
            beat_counter +=1;
        }
        curr_beat_frame = game_settings->getCurrentFrame();

        if (measure_counter == m_song.size() ) {
            measure_counter = 0;
        }
    }
    return 0;
}