#include "FieldView.h"
#include "Mediator.h"
#include "Player.h"
#pragma once

class Game {
private:
    Field field;
    FieldView view;
    Mediator mediator;
    void reaction(Player::Directions move);

public:
    Game();
    void start();
};
