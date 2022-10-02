#include "Cell.h"
#include "Player.h"
#include "random"
#include "utility"
#include <vector>
#pragma once

using namespace std;

class Field {
private:
    int height;
    int width;
    pair<int, int> player_position;
    vector<vector<Cell>> field;

public:
    explicit Field(int a = 10, int b = 10);
    Field(const Field &other);
    Field(Field &&other);
    void swap(Field &other);
    Field &operator=(const Field &other);
    Field &operator=(Field &&other);
    void generate_field();
    void change_player_position(Player::Directions direction);
    int get_height() const;
    int get_width() const;
    vector<vector<Cell>> get_field() const;
};
