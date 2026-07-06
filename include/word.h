#pragma once

#include <bn_sprite_ptr.h>
#include <bn_string.h>
#include <bn_vector.h>
#include <bn_sprite_text_generator.h>
#include <bn_fixed_point.h>

// Maximum word length found in Beowulf was 17, this gives us buffer if needed
static constexpr int MAX_WORD_LEN = 20;

class word {
    public:
        word(bn::sprite_text_generator& gen, bn::string<MAX_WORD_LEN> text, bn::fixed_point _start_position);
        void update();
    private:
        bn::vector<bn::sprite_ptr, MAX_WORD_LEN> _sprs;
        bn::fixed_point _center;
};