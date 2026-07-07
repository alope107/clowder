#pragma once

#include <bn_array.h>
#include <bn_sprite_ptr.h>
#include "bn_sprite_tiles_ptr.h"
#include "bn_sprite_animate_actions.h"

#include "bn_sprite_items_kitty_bard.h"

#include "game.h"

#define ANIMATION_FRAMES 4

class bard
{
public:
    // constructor
    bard(bn::fixed_point position):
        _kitty_bard(bn::sprite_items::kitty_bard.create_sprite(position.x(), position.y())),
        _action(bn::create_sprite_animate_action_forever(
            _kitty_bard, 16, bn::sprite_items::kitty_bard.tiles_item(), 0, 1, 2, 3)) {
    }

    void update(); // call this each frame to advance the animation

private:
    bn::sprite_ptr _kitty_bard;
    bn::sprite_animate_action<4> _action;
};