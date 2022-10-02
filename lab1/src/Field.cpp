#include "Field.h"
using namespace std;

Field::Field(int a, int b) : width(a), height(b), player_position({0, 0}) {
    for (int i = 0; i != height; i++) {
        this->field.emplace_back();
        for (int j = 0; j != width; j++) {
            this->field.at(i).emplace_back();
        }
    }
};

void Field::swap(Field &other) {
    std::swap(height, other.height);
    std::swap(width, other.width);
    std::swap(field, other.field);
    std::swap(player_position, other.player_position);
}

Field &Field::operator=(Field &&other) {
    if (this != &other) {
        this->swap(other);
    }
    return *this;
}

Field::Field(const Field &other) : width(other.width), height(other.height), player_position(other.player_position) {
    for (int i = 0; i != height; i++) {
        this->field.emplace_back();
        for (int j = 0; j != width; j++) {
            Cell new_cell(other.field.at(i).at(j));
            this->field.at(i).push_back(new_cell);
        }
    }
}

Field::Field(Field &&other) {
    this->swap(other);
}

Field &Field::operator=(const Field &other) {
    if (this != &other)
        Field(other).swap(*this);

    return *this;
}

void Field::generate_field() {
    field.at(0).at(0).set_type(Cell::PLAYER);
    for (int i = 0; i != this->height; i++) {
        int pos = (i == 0 ? 1 : 0);
        for (int j = pos; j != this->width; j++) {
            field.at(i).at(j).set_type(Cell::STANDARD);
            random_device dev;
            mt19937 random_gen(dev());
            uniform_int_distribution<mt19937::result_type> u_i_distr(1, 7);
            switch (u_i_distr(random_gen)) {
            case 1:
                field.at(i).at(j).set_type(Cell::WALL);
                break;
            case 2:
                field.at(i).at(j).set_type(Cell::Coin);
                break;
            default:
                break;
            }
        }
    }
}

void Field::change_player_position(Player::Directions direction) {
    field.at(player_position.second).at(player_position.first).set_type(Cell::STANDARD);
    pair<int, int> temp = this->player_position;

    switch (direction) {
    case Player::UP:
        temp.second--;
        break;
    case Player::DOWN:
        temp.second++;
        break;
    case Player::LEFT:
        temp.first--;
        break;
    case Player::RIGHT:
        temp.first++;
        break;
    }

    temp.first = temp.first % width;
    temp.second = temp.second % height;

    if (temp.first < 0)
        temp.first += width;
    if (temp.second < 0)
        temp.second += height;

    if (this->field.at(temp.second).at(temp.first).get_celltype() == Cell::WALL) {
        this->player_position = this->player_position;
    } else {
        this->player_position = temp;
    }

    field.at(player_position.second).at(player_position.first).set_type(Cell::PLAYER);
}

int Field::get_height() const {
    return this->height;
};

int Field::get_width() const {
    return this->width;
};

vector<vector<Cell>> Field::get_field() const {
    return this->field;
}
