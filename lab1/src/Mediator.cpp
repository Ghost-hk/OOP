#include "Mediator.h"
using namespace std;

pair<int, int> Mediator::field_size() {
    cout << "Enter the width of the field:\n";
    int width = reader.read_number();
    if (width < 1 || width > 25) {
        cout << "Incorect value!\nThe width will be set to 10.\n";
        width = 10;
    }
    cout << "Eneter the height of the field:\n";
    int height = reader.read_number();
    if (height < 1 || height > 25) {
        cout << "Incorect value!\nThe height will be set to 10.\n";
        height = 10;
    }
    return pair<int, int>({width, height});
}

Player::Directions Mediator::move() {
    cout << "Enter the direction of movment(w, a, s, d), and type e to exit:";
    return reader.get_step();
}
