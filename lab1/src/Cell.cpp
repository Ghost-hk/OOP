#include "Cell.h"

Cell::Cell() : type(CellType::STANDARD), event(nullptr){};

Cell::CellType Cell::get_celltype() const {
    return this->type;
}

void Cell::set_type(Cell::CellType type) {
    this->type = type;
};

void Cell::set_event(Event *event) {
    this->event = event;
};

void Cell::update() {
    if (event != nullptr || type == PLAYER) {
        event->Execute();
    }
};