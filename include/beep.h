#pragma once

#include <bn_vector.h>
#include <bn_sound_item.h>
#include <bn_unordered_map.h>
#include "game.h"
#include "limits.h"
#include "measure.h"

class beep
{
public:
    // constructor
    beep(game *settings, song in_song) {
        beat_counter = 0;
        measure_counter = 0;
        game_settings = settings;
        game_fpb = game_settings->getFramesPerBeat();
        m_song = in_song;
    }

    void update(); // call this to run the beep

    void setBeats(song in_song) { 
        m_song = in_song; 
    }

    int getMeasure() { return measure_counter; }
    int getBeat() { return beat_counter; }
    bn::vector<int, MAX_MEASURE_LEN> getHitFrames() { return hit_frames; }

private:
    game *game_settings;
    song m_song;
    int beat_counter;
    int measure_counter;
    int game_fpb;
    int curr_beat_frame = 0;
    bn::vector<int, MAX_MEASURE_LEN> hit_frames;

    // helper functions
    int beat(int currFrame); // returns frame number for the frame that play happened
    int play(); 
};