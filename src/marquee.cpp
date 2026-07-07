#include "marquee.h"

marquee::marquee(bn::sprite_text_generator& gen,
                 bn::vector<bn::string<MAX_WORD_LEN>, MAX_MARQUEE_WORDS> text,
                 bn::fixed_point start_pos,
                 int frames_per_spawn,
                bn::fixed text_speed) :
    _gen(gen),
    _text(text),
    _start_pos(start_pos),
    _text_idx(0),
    _text_speed(text_speed),
    _frames_per_spawn(frames_per_spawn),
    _frames_to_spawn(0)
     {
}

void marquee::update() {
    for(word& w : _words) {
        w.update();
    }

    if(_frames_to_spawn-- > 0) return;

    _frames_to_spawn = _frames_per_spawn;

    if(_text_idx < _text.size()) {
        _words.emplace_back(_gen, _text[_text_idx++], _start_pos, _text_speed);
    }
}

