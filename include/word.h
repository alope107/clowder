#pragma once

#include <bn_sprite_ptr.h>
#include <bn_string.h>
#include <bn_vector.h>
#include <bn_sprite_text_generator.h>
#include <bn_fixed_point.h>

#include "limits.h"

class word {
    public:
        word(bn::sprite_text_generator& gen,
             bn::string<MAX_WORD_LEN> text,
             bn::fixed_point start_position,
             bn::fixed speed);
        void update();
    private:
        bn::vector<bn::sprite_ptr, MAX_WORD_LEN> _sprs;
        bn::fixed_point _center;
        bn::fixed _speed;
};