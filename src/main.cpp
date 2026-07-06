#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>

#include "word.h"

#include "common_fixed_8x16_font.h"

int main() {
    bn::core::init();

    bn::backdrop::set_color(bn::color(31, 0, 0));

    bn::sprite_font font = common::fixed_8x16_sprite_font;
    bn::sprite_text_generator text_generator(font);
    text_generator.set_alignment(bn::sprite_text_generator::alignment_type::CENTER);

    word w = word(text_generator, "hw|t", {30, 30});

    while(true) {
        if(bn::keypad::a_pressed()) {
            bn::backdrop::set_color(bn::color(0, 0, 30));
        }
        if(bn::keypad::b_pressed()) {
            bn::backdrop::set_color(bn::color(0, 31, 0));
        }
        w.update();
        bn::core::update();
    }
}