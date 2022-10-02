#include "Player.h"
#include "iostream"
#pragma once

class CommandReader {
public:
    CommandReader() = default;
    ~CommandReader() = default;
    int read_number() const;
    Player::Directions get_step() const;
};