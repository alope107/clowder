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

int main()
{
    game gameSettings(60);
    beep sound(gameSettings);

    bn::core::init();

    bn::backdrop::set_color(bn::color(31, 0, 0));

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
        bn::core::update();
    }
}