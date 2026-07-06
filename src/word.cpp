#include "word.h"

word::word(bn::sprite_text_generator& gen, bn::string<MAX_WORD_LEN> text, bn::fixed_point _start_position) : _center(_start_position) {
    gen.generate(0, 0, text, _sprs);
    for(auto& spr : _sprs) {
        spr.set_position(spr.position() + _start_position);
    }
}

void word::update() {
    bn::fixed speed = -1;
    _center += {speed, 0};
    for(auto& spr : _sprs) {
        spr.set_x(spr.x() + speed);
    }
}