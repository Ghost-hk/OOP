#include "FieldView.h"

void FieldView::write_field(const Field &field) const {
    system("clear");
    write_horizontal_border(field.get_width());

    for (int i = 0; i != field.get_height(); ++i) {
        std::cout << "| ";
        for (int j = 0; j != field.get_width(); ++j) {
            std::cout << CellView(field.get_field().at(i).at(j)).get_view() << "  ";
        }
        std::cout << "|\n";
    }

    write_horizontal_border(field.get_width());
}

void FieldView::write_horizontal_border(int width) const {
    for (int i = 0; i != width + 1; i++) {
        std::cout << "---";
    }
    std::cout << '\n';
}