#pragma once

class Player {
private:
    int hearts;
    int coins;
    int power;

public:
    enum Directions {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        EXIT,
        NOTHING
    };
    explicit Player(int hearts = 3, int power = 1);
    int get_hearts() const;
    int get_coins() const;
    int get_power() const;
    void set_hearts(int heart);
    void set_power(int dmg);
    void set_coins(int coin);
    void add_coin();
};
