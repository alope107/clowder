#include "word.h"

word::word(bn::sprite_text_generator& gen,
           bn::string<MAX_WORD_LEN> text,
           bn::fixed_point start_position,
           bn::fixed speed) : 
           _center(start_position),
           _speed(speed) {
    gen.generate(0, 0, text, _sprs);
    for(auto& spr : _sprs) {
        spr.set_position(spr.position() + _center);
    }
}

void word::update() {
    _center += {_speed, 0};
    for(auto& spr : _sprs) {
        spr.set_x(spr.x() + _speed);
    }
}