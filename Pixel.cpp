#include "Pixel.h"
#include <iostream>

using namespace std;

#define RESET "\033[0m"
#define BLINK "\033[5m"
#define WHITE "\033[0;37m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define BLACK "\033[0;30m"    // Black
#define GREEN "\033[0;32m"    // Green
#define CYAN "\033[0;36m"     // Cyan
#define MAGENTA "\033[0;35m"  // Magenta
#define GREY "\033[0;90m"     // Grey (Bright Black)
#define ORANGE "\033[38;5;214m" 

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
