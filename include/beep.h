#pragma once

#include <bn_vector.h>
#include <bn_sound_item.h>
#include <bn_unordered_map.h>
#include "game.h"
class beep
{
public:
    // constructor
    beep(game settings) {
        beat_counter = 1;
        game_bpm = settings.getGameBPM();
    }

    int beat(int currFrame); // returns frame number for the frame that play happened
    int play(bn::unordered_map<int, int, 4> beats);
    int play(bn::vector<int, 4> beats); 


private:
    int beat_counter;
    int game_bpm;

};