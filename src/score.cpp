#include "score.h"

void score::update() {
    int points = _state->getScore();
    _kitten_1.set_visible(5 < points);
    _kitten_2.set_visible(10 < points);
    _kitten_3.set_visible(15 < points);
    _kitten_4.set_visible(20 < points);
    _kitten_5.set_visible(25 < points);
    _kitten_6.set_visible(30 < points);

    _action_1.update();
    _action_2.update();
    _action_3.update();
    _action_4.update();
    _action_5.update();
    _action_6.update();
}