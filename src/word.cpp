#include "word.h"

word::word(bn::sprite_text_generator &gen,
           bn::string<MAX_WORD_LEN> text,
           bn::fixed_point start_position,
           bn::fixed speed) : _text(text),
                              _left(start_position),
                              _speed(speed)
{
    gen.generate(0, 0, text, _sprs);
    for (auto &spr : _sprs)
    {
        spr.set_position(spr.position() + _left);
    }
}

void word::update()
{
    _left += {_speed, 0};
    for (auto &spr : _sprs)
    {
        spr.set_x(spr.x() + _speed);
    }
}

bn::fixed_point word::left() {
    return _left;
}

bn::string_view word::text() {
    return _text;
}