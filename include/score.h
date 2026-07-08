#pragma once

#include <bn_array.h>
#include <bn_sprite_ptr.h>
#include "bn_sprite_tiles_ptr.h"
#include "bn_sprite_animate_actions.h"

#include "bn_sprite_items_kitty_bard.h"
#include "bn_sprite_items_kitten_laying.h"
#include "bn_sprite_items_kitten_sitting.h"
#include "bn_sprite_items_kitten_demonic.h"

#include "game.h"

#define ANIMATION_FRAMES 4

class score
{
public:
    // constructor
    score(game *state, bn::fixed_point position):
        _state(state),
        _kitten_1(bn::sprite_items::kitten_laying.create_sprite(position.x(), position.y())),
        _kitten_4(bn::sprite_items::kitten_sitting.create_sprite(position.x() + 32, position.y())),
        _kitten_2(bn::sprite_items::kitten_laying.create_sprite(position.x() + 2*32, position.y())),
        _kitten_5(bn::sprite_items::kitten_sitting.create_sprite(position.x() + 3*32, position.y())),
        _kitten_3(bn::sprite_items::kitten_laying.create_sprite(position.x() + 4*32, position.y())),
        _kitten_6(bn::sprite_items::kitten_demonic.create_sprite(position.x() + 5*32, position.y() - 16)),
        
        _action_1(bn::create_sprite_animate_action_forever(
            _kitten_1, 32, bn::sprite_items::kitten_laying.tiles_item(), 0, 1, 2)),
        _action_2(bn::create_sprite_animate_action_forever(
            _kitten_2, 27, bn::sprite_items::kitten_laying.tiles_item(), 0, 1, 2)),
        _action_3(bn::create_sprite_animate_action_forever(
            _kitten_3, 25, bn::sprite_items::kitten_laying.tiles_item(), 0, 1, 2)),
        _action_4(bn::create_sprite_animate_action_forever(
            _kitten_4, 49, bn::sprite_items::kitten_sitting.tiles_item(), 0, 1, 2, 3, 4, 5)),
        _action_5(bn::create_sprite_animate_action_forever(
            _kitten_5, 22, bn::sprite_items::kitten_sitting.tiles_item(), 0, 1, 2, 3, 4, 5)),
        _action_6(bn::create_sprite_animate_action_forever(
            _kitten_6, 11, bn::sprite_items::kitten_demonic.tiles_item(), 0, 1, 2, 3))
        {}

    void update();

private:
    game *_state;
    bn::sprite_ptr _kitten_1;
    bn::sprite_ptr _kitten_2;
    bn::sprite_ptr _kitten_3;
    bn::sprite_ptr _kitten_4;
    bn::sprite_ptr _kitten_5;
    bn::sprite_ptr _kitten_6;
    //bn::sprite_ptr _kitten_7;
    //bn::sprite_ptr _kitten_8;
    bn::sprite_animate_action<3> _action_1;
    bn::sprite_animate_action<3> _action_2;
    bn::sprite_animate_action<3> _action_3;
    bn::sprite_animate_action<6> _action_4;
    bn::sprite_animate_action<6> _action_5;
    bn::sprite_animate_action<4> _action_6;
    /*
    bn::sprite_animate_action<6> _action_7;
    bn::sprite_animate_action<4> _action_8;
    */
};