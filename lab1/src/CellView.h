#include "Cell.h"
#pragma once

class CellView {
private:
    char cell_view;

public:
    explicit CellView(const Cell &cell);
    char get_view() const;
};
