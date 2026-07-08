#pragma once

#include <bn_log.h>

class game
{
public:
    game(int bpm)
    {
        score = 0;
        // init frame to 0
        current_frame = 0;
        game_bpm = bpm;
        game_fpb = (game_fps * 60) / game_bpm;
        loop_count = 0;
    }

    int getCurrentFrame() { return current_frame; };
    int incrementFrame(bool logFrame = false)
    {
        current_frame += 1;
        if (logFrame)
            BN_LOG(current_frame);
        return current_frame;
    };

    int getScore() { return score; }
    void setScore(int x) { 
        if (x < 0) 
            x = 0;
        score = x; 
    }
    int getFramesPerBeat() { return game_fpb; };
    int getSuccessThreshold() { return success_threshold;  }
    void setSuccessThreshold(int x) { success_threshold = x; }
    void incrementLoopCount() { loop_count += 1; }
    int getLoopCount() { return loop_count; }
private:
    int score; // score
    int success_threshold; 
    int current_frame;
    int game_bpm; // beat per minute 
    int game_fps = 60; // frames per second
    int game_fpb; // frames per beat (if beat is 16th note)
    int loop_count; // keeps track of how many times the song has looped
};