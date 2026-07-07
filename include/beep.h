#pragma once

#include <bn_vector.h>
#include <bn_sound_item.h>
#include <bn_unordered_map.h>
#include "game.h"
class beep
{
public:
    // constructor
    beep(game *settings, bn::vector<int, 4> in_beats) {
        beat_counter = 1;
        game_settings = settings;
        game_bpm = game_settings->getFramesPerBeat();
        beats = in_beats;
    }

    void update(); // call this to run the beep

    int setBeats(bn::vector<int, 4> in_beats) { 
        beats = in_beats; 
        return 0;
    }

private:
    game *game_settings;
    int beat_counter;
    int game_bpm;
    bn::vector<int, 4> beats;

    // helper functions
    int beat(int currFrame); // returns frame number for the frame that play happened
    int play(bn::unordered_map<int, int, 4> in_beats);
    int play(bn::vector<int, 4> in_beats); 
};