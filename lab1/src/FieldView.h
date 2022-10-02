#include "CellView.h"
#include "Field.h"
#include "iostream"
#pragma once

class FieldView {
private:
    void write_horizontal_border(int width) const;

public:
    void write_field(const Field &field) const;
};
