#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>
#include <bn_string.h>

#include "word.h"
#include "marquee.h"

#include "common_fixed_8x16_font.h"

int main() {
    bn::core::init();

    bn::backdrop::set_color(bn::color(31, 0, 0));

    bn::sprite_font font = common::fixed_8x16_sprite_font;
    bn::sprite_text_generator text_generator(font);
    text_generator.set_alignment(bn::sprite_text_generator::alignment_type::CENTER);

    // int a = 5;

    // bn::vector<int, MAX_MARQUEE_WORDS> huh = {
    //     a, a
    // };

    bn::vector<bn::string<MAX_WORD_LEN>, MAX_MARQUEE_WORDS> text = {};

    //Hwæt. We Gardena in geardagum,
    //þeodcyninga, þrym gefrunon
    text.push_back(bn::string<MAX_WORD_LEN>("Hw|t"));
    text.push_back(bn::string<MAX_WORD_LEN>("We"));
    text.push_back(bn::string<MAX_WORD_LEN>("Gardena"));
    text.push_back(bn::string<MAX_WORD_LEN>("in"));
    text.push_back(bn::string<MAX_WORD_LEN>("geardagum"));
    text.push_back(bn::string<MAX_WORD_LEN>("}eodcyninga"));
    text.push_back(bn::string<MAX_WORD_LEN>("}rym"));
    text.push_back(bn::string<MAX_WORD_LEN>("gefrunon"));

    marquee m = marquee(text_generator,
                        text,
                        {200, -30},
                        80
                        );

    while(true) {
        if(bn::keypad::a_pressed()) {
            bn::backdrop::set_color(bn::color(0, 0, 30));
        }
        if(bn::keypad::b_pressed()) {
            bn::backdrop::set_color(bn::color(0, 31, 0));
        }
        m.update();
        bn::core::update();
    }
}