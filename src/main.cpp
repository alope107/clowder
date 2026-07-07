
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

#include "bard.h"
#include "word.h"
#include "marquee.h"

#include "common_variable_8x16_sprite_font.h"


int main()
{
    // set bpm
    game gameSettings(80);

    song my_song;
    // todo: add metronome start so they can get the beat
    my_song.push_back(0b0001'0001'0001'0101);
    my_song.push_back(0b0000'0000'0000'0000);
    my_song.push_back(0b0001'0001'0001'0101);
    my_song.push_back(0b0000'0000'0000'0000);
    my_song.push_back(0b0101'0101'0001'0101);
    my_song.push_back(0b0000'0000'0000'0000);
    my_song.push_back(0b0101'0001'0001'0001);
    my_song.push_back(0b0000'0000'0000'0000);
    beep sound(&gameSettings, my_song);

    bn::core::init();

    bn::backdrop::set_color(bn::color(15, 27, 31));

    bn::sprite_font font = common::variable_8x16_sprite_font;
    bn::sprite_text_generator text_generator(font);
    text_generator.set_alignment(bn::sprite_text_generator::alignment_type::LEFT);

    bard kitty_bard = bard({-120 + 32, 0});

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
        "geardagum", 
        "test",
        "test",
        "test",
        "test",
        "test",
        "test",
        "test",
        "test",
        "test",
        "test",
        "test",
        "test",
        "test",
        "test",
        "test",
        "test",
        "test",
        "test",
        "test",
        "test",
        "test",
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
        if (bn::keypad::a_pressed() || bn::keypad::b_pressed())
        {
            int checkMeasure = sound.getMeasure() - 1;
            int checkBeat = sound.getBeat();
            if (play_beat(my_song[checkMeasure], checkBeat))
                m.pop_word(true);            
        }

        kitty_bard.update();
        sound.update(); 
        m.update();
        gameSettings.incrementFrame();
        bn::core::update();
    }

}
