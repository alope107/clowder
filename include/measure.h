#pragma once
#include <bn_vector.h>
#include "limits.h"

using measure = unsigned short; // 16 bits
using song = bn::vector<measure, MAX_SONG_LEN>;

//<0, 4, 8, 12>
// 0001 0001 0001 0001 --> 4369
// beat = 0, return true
// beat = 4 return true
// beat = 3 return false
// return true if beat should be played in current measure
// return false if beat should not be played in current measure 
bool play_beat(measure current_measure, int beat) {
    unsigned short bitmask = 1 << beat;
    return current_measure & bitmask > 0;
}
