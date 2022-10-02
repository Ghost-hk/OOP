#include "Event.h"
#include "Player.h"
#pragma once

class Cell {
public:
    enum CellType {
        STANDARD,
        PLAYER,
        WALL,
        Coin
    };

private:
    CellType type;
    Event *event;

public:
    Cell();
    CellType get_celltype() const;
    void set_type(CellType type);
    void set_event(Event *event);
    void update();
};