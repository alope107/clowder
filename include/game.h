#pragma once

#include <bn_log.h>

class game
{
public:
    game(int bpm)
    {
        // init frame to 0
        current_frame = 0;
        game_bpm = bpm;
        game_fpb = game_fps / (game_bpm / 60);
    }

    int getCurrentFrame() { return current_frame; };
    int incrementFrame(bool logFrame = false)
    {
        current_frame += 1;
        if (logFrame)
            BN_LOG(current_frame);
        return current_frame;
    };

    int getFramesPerBeat() { return game_fpb; };

private:
    int current_frame;
    int game_bpm; // beat per minute 
    int game_fps = 60; // frames per second
    int game_fpb; // frames per beat
};