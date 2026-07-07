
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
#include "limits.h"

#include <bn_string.h>

#include "word.h"
#include "marquee.h"

#include "common_variable_8x16_sprite_font.h"

int main()
{
    // set bpm
    game gameSettings(120);

    // make sound vector
    bn::vector<int, MAX_MEASURE_LEN> beats_vec;
    beats_vec.push_back(0);
    beats_vec.push_back(2);
    beats_vec.push_back(4);
    beats_vec.push_back(8);
    beats_vec.push_back(12);


    //beats_vec.push_back(8);
    //beats_vec.push_back(12);
    //beats_vec.push_back(16);
    
    
    // init beep

    song my_song;
    my_song.push_back(0b0001'0001'0001'0101);
    my_song.push_back(0b0001'0001'0001'0101);
    my_song.push_back(0b0101'0101'0001'0101);
    my_song.push_back(0b0101'0001'0001'0001);
    beep sound(&gameSettings, my_song);

    bn::core::init();

    bn::backdrop::set_color(bn::color(31, 0, 0));

    bn::sprite_font font = common::variable_8x16_sprite_font;
    bn::sprite_text_generator text_generator(font);
    text_generator.set_alignment(bn::sprite_text_generator::alignment_type::LEFT);

    //Hwæt. We Gardena in geardagum,
    //þeodcyninga, þrym gefrunon
    constexpr bn::string_view text[] = {
        "Hw|t",
        "We",
        "Gardena",
        "in",
        "geardagum",
        "}eodcyninga",
        "}rym",
        "gefrunon",
        "Hw|t",
        "We",
        "Gardena",
        "in",
        "geardagum",
        "}eodcyninga",
        "}rym",
        "gefrunon",
        "Hw|t",
        "We",
        "Gardena",
        "in",
        "geardagum"
    };

    marquee m = marquee(text_generator,
                        (int)(sizeof(text) / sizeof(text[0])),
                        text,
                        {120, -30},
                        -100,
                        gameSettings.getFramesPerBeat(),
                        -1
                        );


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

        sound.update(); 
        m.update();
        gameSettings.incrementFrame();
        bn::core::update();
    }

}
