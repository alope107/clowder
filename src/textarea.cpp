#include "textarea.h"

#include <bn_log.h>

// how many pixels taken up by a space in text
static constexpr int SPACE_WIDTH = 8;
static constexpr int CHAR_WIDTH = 8;

textarea::textarea(bn::sprite_text_generator& gen, 
                 bn::fixed_point start,
                 bn::fixed max_x) :
                _gen(gen),
                _lines(),
                _sprs(),
                _start(start),
                _max_line_width(max_x - start.x()),
                _line(0){
    clear();
}

void textarea::clear() {
    _lines.clear();
    _lines.push_back("");
    _sprs.clear();
    _line = 0;
    _line_width = 0;
}

int string_width(bn::string_view word, [[maybe_unused]] const bn::sprite_font & font) {
    auto widths = font.character_widths_ref();
    BN_LOG("widths size", widths.size());
    constexpr char STARTING_CHAR = 32;
    int total_width = 0;
    for (const char c : word) {
        total_width += widths[c - STARTING_CHAR];
    }
    return total_width;
}

void textarea::add_word(bn::string_view word) {
    // TODO: Optimize repeated fit checks?
    BN_ASSERT(fits(word), "Word does not fit in textarea");

    if(!_fits_on_line(word)) {
        _line++;
        _line_width = 0;
        _lines.push_back("");
    } else {
        if(_lines[0].size() > 0) {
            _lines[_line] += " ";
            _line_width += SPACE_WIDTH;
        }
    }

    _line_width += string_width(word, _gen.font());
    _lines[_line] += word;

    _sprs.clear();
    for(int i = 0; i < _lines.size(); i++) {
        bn::fixed y = _start.y() + i*LINE_HEIGHT;
        _gen.generate(_start.x(), y, _lines[i], _sprs);
    }
}

// makes simplifying assumption that no single word will be wider than the full line width
bool textarea::fits(bn::string_view word) {
    return _fits_on_line(word) || _line < (MAX_TEXTAREA_LINES - 1);
}

bool textarea::_fits_on_line(bn::string_view word) {
    int requested_width = string_width(word, _gen.font()) + SPACE_WIDTH;
    return _line_width + requested_width < _max_line_width;
}