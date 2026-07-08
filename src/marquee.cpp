#include "marquee.h"

#include <bn_log.h>
#include <bn_math.h>

static constexpr int FAKE_TOLERANCE = 5;

bn::fixed calc_text_speed(bn::fixed x_start, bn::fixed x_cutoff, int frames_per_beat) {
    int frames_per_measure = frames_per_beat * 4;
    bn::fixed distance = x_start - x_cutoff;
    return -distance / frames_per_measure;
}

marquee::marquee(bn::sprite_text_generator& gen, 
                int text_count,
                const bn::string_view text[],
                bn::fixed_point start_pos,
                int frames_thresh,
                bn::fixed cutoff,
                bn::fixed text_speed,
                int frames_per_beat,
                song rhythm) :
    _textarea(gen, {-100 + 64, -30}, 100),
    _gen(gen),
    _text_count(text_count),
    _text(text),
    _start_pos(start_pos),
    _text_idx(0),
    _text_speed(calc_text_speed(_start_pos.x(), cutoff, frames_per_beat)),
    _cutoff(cutoff + (_text_speed*frames_thresh)),
    _frames_per_beat(frames_per_beat),
    _rhythm(rhythm),
    _frame(0)
     {
}



void marquee::pop_word(bool success) {
    word& front = _words[0];
    if (!success) {
        front = word(_gen, "*****", _start_pos, _text_speed);
    }
    if(!_textarea.fits(front.text())) _textarea.clear();
            _textarea.add_word(front.text());
            _words.pop_front();
}

void marquee::update() {
    for(word& w : _words) {
        w.update();
    }

    if(_words.size() > 0) {
        word& front = _words[0];
        if(front.left().x() < _cutoff) {
            pop_word(false);
        }
    }

    // BN_LOG("rsize ", _rhythm.size());

    // BN_LOG("fpb ", _frames_per_beat);

    int frames_per_sixteen = _frames_per_beat / 4;
    int measure_length = frames_per_sixteen * 16;

    //  BN_LOG("frame ", _frame);
    //  BN_LOG("fpb ", _frames_per_beat);
    //  BN_LOG("fp16 ", frames_per_sixteen);

    int measure_idx = (_frame / measure_length) % _rhythm.size();
    int sixteen_idx = (_frame / frames_per_sixteen) % 16;

    // BN_LOG("measureidx ", measure_idx);
    // BN_LOG("sixteen_idx ", sixteen_idx);

    if(_text_idx < _text_count && _frame % frames_per_sixteen == 0 && play_beat(_rhythm[measure_idx], sixteen_idx)) {
        auto pos = bn::fixed_point(_start_pos);
        auto mod = _text_idx % 3;
        if (mod == 0) {
            pos.set_y(_start_pos.y() + 10);
        } else if (mod == 1) {
        } else {
            pos.set_y(_start_pos.y() - 10);
        }
        
        _words.emplace_back(_gen, _text[_text_idx++], pos, _text_speed);
    }
    _frame++;
}

