#pragma once

#include <bn_log.h>

class game
{
public:
    game()
    {
        // init frame to 0
        current_frame = 0;
    }

    int getCurrentFrame() { return current_frame; };
    int incrementFrame(bool logFrame = false)
    {
        current_frame += 1;
        if (logFrame)
            BN_LOG(current_frame);
        return current_frame;
    };

private:
    int current_frame;
};