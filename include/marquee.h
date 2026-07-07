#pragma once

#include <bn_deque.h>
#include <bn_sprite_ptr.h>

#include "word.h"
#include "limits.h"
#include "textarea.h"
#include "measure.h"

static constexpr int MAX_MARQUEE_WORDS = 32;


class marquee {
    public:
        marquee(bn::sprite_text_generator& gen, // TODO: Marquee should probably create and own the etxt generator
                int text_count,
                const bn::string_view text[],
                bn::fixed_point start_pos,
                bn::fixed cutoff,
                bn::fixed text_speed,
                int frames_per_beat,
                song rhythm);
        void update();
        void pop_word(bool success);

    private:
        bn::sprite_ptr _target;
        textarea _textarea;
        bn::sprite_text_generator& _gen;
        int _text_count;
        const bn::string_view *_text;
        bn::fixed_point _start_pos;
        int _text_idx;
        bn::deque<word, MAX_MARQUEE_WORDS> _words;
        bn::fixed _text_speed;
        bn::fixed _cutoff;
        int _frames_per_beat;
        song _rhythm;
        int _frame;
};