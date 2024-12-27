#include "Pixel.h"
#include <iostream>

using namespace std;

#define RESET "\033[0m"
#define WHITE "\033[0;37m"s
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define BLINK "\033[5m"

Pixel::Pixel(int x, int y) {
    on = false;
    selected = false; 
    color = WHITE;
    position = {x, y};
    visualPixel = "лл";
 
}

void Pixel::setColor(string color) {
    this->color = color;
}

string Pixel::getColor() {
    return color;
}

void Pixel::printVisualPixel() {
    cout << ((selected) ? BLINK : RESET) << color << visualPixel;

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
