#include "Pixel.h"
#include <iostream>

using namespace std;

Pixel::Pixel(int x, int y) {
    selected = false; 
    color = WHITE;
    position = {x, y};
    visualPixel = "ÛÛ";
}

void Pixel::setColor(string color) {
    this->color = color;
}

string Pixel::getColor() {
    return color;
}

void Pixel::printVisualPixel() {
    if (getSelected()) {
        cout << BLINK << color << char(176) << char(176) << RESET;
    }
    else {
        cout << RESET << getColor() << visualPixel;
    }


}
void Pixel::setPosition(pair<int,int> position) {
    this->position = position;
}

pair<int, int> Pixel::getPosition() {
    return position; 
}

bool Pixel::getSelected() {
    return selected;
}

void Pixel::setSelected(bool tf) {
    selected = tf;
}
