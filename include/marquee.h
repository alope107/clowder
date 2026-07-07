#pragma once

#include <bn_deque.h>

#include "word.h"
#include "limits.h"

static constexpr int MAX_MARQUEE_WORDS = 16;


class marquee {
    public:
        marquee(bn::sprite_text_generator& gen, // TODO: Marquee should probably create and own the etxt generator
                bn::vector<bn::string<MAX_WORD_LEN>, MAX_MARQUEE_WORDS> text,
                bn::fixed_point start_pos,
                int frames_per_spawn,
                bn::fixed text_speed);
        void update();
    private:
        bn::sprite_text_generator& _gen;
        bn::vector<bn::string<MAX_WORD_LEN>, MAX_MARQUEE_WORDS> _text;
        bn::fixed_point _start_pos;
        int _text_idx;
        bn::deque<word, MAX_MARQUEE_WORDS> _words;
        bn::fixed _text_speed;
        int _frames_per_spawn;
        int _frames_to_spawn;
};