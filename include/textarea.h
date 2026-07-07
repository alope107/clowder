#pragma once

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_text_generator.h>
#include <bn_string.h>
#include <bn_vector.h>

#include "limits.h"

static constexpr int MAX_TEXTAREA_LINES = 2;
static constexpr int MAX_TEXTAREA_CHARS = MAX_LINE_LEN*MAX_TEXTAREA_LINES;
static constexpr int LINE_HEIGHT = 18;


class textarea {
    public:
        textarea(bn::sprite_text_generator& gen, 
                 bn::fixed_point start,
                 bn::fixed max_x);
        void clear();
        bool fits(bn::string_view word);
        void add_word(bn::string_view word);
    private:
        bool _fits_on_line(bn::string_view word);

        bn::sprite_text_generator& _gen;
        bn::vector<bn::string<MAX_LINE_LEN>, MAX_TEXTAREA_LINES> _lines;
        bn::vector<bn::sprite_ptr, MAX_TEXTAREA_CHARS> _sprs; // sprites for the text, should be far more than enough
        bn::fixed_point _start;
        bn::fixed _max_line_width;

        int _line; // index of line currently being edited
        int _line_width; // width (in pixels) of the line currently being edited
};