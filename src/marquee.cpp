#include "marquee.h"

marquee::marquee(bn::sprite_text_generator& gen,
                 int text_count,
                 const bn::string_view text[],
                 bn::fixed_point start_pos,
                 bn::fixed cutoff,
                 int frames_per_spawn,
                bn::fixed text_speed) :
    _textarea(gen, {-100 + 64, 0}, 100),
    _gen(gen),
    _text_count(text_count),
    _text(text),
    _start_pos(start_pos),
    _text_idx(0),
    _text_speed(text_speed),
    _cutoff(cutoff),
    _frames_per_spawn(frames_per_spawn),
    _frames_to_spawn(0)
     {
}

void marquee::update() {
    for(word& w : _words) {
        w.update();
    }

    if(_words.size() > 0) {
        word& front = _words[0];
        if(front.left().x() < _cutoff) {
            if(!_textarea.fits(front.text())) _textarea.clear();
            _textarea.add_word(front.text());
            _words.pop_front();
        }
    }
    
    if(_frames_to_spawn-- > 0) return;

    _frames_to_spawn = _frames_per_spawn;

    if(_text_idx < _text_count) {
        _words.emplace_back(_gen, _text[_text_idx++], _start_pos, _text_speed);
    }
}

