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
        song_bps = game_fps / (game_bpm / 60);
    }

    int getCurrentFrame() { return current_frame; };
    int incrementFrame(bool logFrame = false)
    {
        current_frame += 1;
        if (logFrame)
            BN_LOG(current_frame);
        return current_frame;
    };

    int getGameBPM() { return song_bps; };

private:
    int current_frame;
    int game_bpm;
    int game_fps = 60;
    int song_bps;
};