#include "CommandReader.h"
#pragma once

class Mediator {
private:
    CommandReader reader;

public:
    Mediator() : reader(CommandReader()){};
    std::pair<int, int> field_size();
    Player::Directions move();
};