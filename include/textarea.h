#pragma once

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_vector.h>

#include "limits.h"

class textarea {
    public:
        textarea(bn::fixed_point start, bn::fixed max_x);
    private:
        bn::vector<bn::sprite_ptr, MAX_LINE_LEN*2> _sprs; // sprites for the text, should be far more than enough
};