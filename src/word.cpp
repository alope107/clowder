#include "word.h"

word::word(bn::sprite_text_generator& gen, bn::string<MAX_WORD_LEN> text) {
    gen.generate(0, 0, text, _sprs);
}