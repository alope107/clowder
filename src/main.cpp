
#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>
#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_sound.h>
#include <bn_sound_item.h>
#include <bn_log.h>
#include "bn_sound_items.h"
#include <bn_vector.h>
#include <bn_unordered_map.h>
#include "beep.h"

#include "game.h"

#include <bn_string.h>

#include "word.h"
#include "marquee.h"

#include "common_fixed_8x16_font.h"

int main()
{
    game gameSettings(60);
    beep sound(gameSettings);

    bn::core::init();

    bn::backdrop::set_color(bn::color(31, 0, 0));

    bn::sprite_font font = common::fixed_8x16_sprite_font;
    bn::sprite_text_generator text_generator(font);
    text_generator.set_alignment(bn::sprite_text_generator::alignment_type::CENTER);


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

    // load sprite
    // bn::sprite_ptr heart = bn::sprite_items::heart.create_sprite(); // by default in middle, sprite ptr is a smart pointer

    while (true)
    {
        if (bn::keypad::a_pressed())
        {
            bn::backdrop::set_color(bn::color(0, 0, 30));
            bn::sound::play(bn::sound_items::clap_lo);
        }
        if (bn::keypad::b_pressed())
        {
            bn::backdrop::set_color(bn::color(0, 31, 0));
            bn::sound::play(bn::sound_items::clap_hi);
        }
       
        int currFrame = gameSettings.getCurrentFrame();
        sound.beat(currFrame);

        // make sound with map
        bn::unordered_map<int, int, 4> beats;
        beats[1] = 0;
        beats[3] = 0;
        //sound.play(beats);

        // make sound vector
        bn::vector<int, 4> beats_vec;
        beats_vec.push_back(1);
        beats_vec.push_back(3);
        sound.play(beats_vec);
        

        gameSettings.incrementFrame();
        m.update();
        bn::core::update();
    }

}