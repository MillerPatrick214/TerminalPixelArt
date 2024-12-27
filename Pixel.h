#ifndef PIXEL_H
#define PIXEL_H

#include <string>
#include <utility>
#include <vector>

using namespace std;

class Pixel {
 private:
    bool on;
    bool selected;
    string color;
    pair<int, int> position;
 
 
 public:

    string visualPixel;
    Pixel(int x, int y);
    void setColor(string color);
    void printVisualPixel();
    string getColor();
    void setSelected(bool tf);
    bool getSelected();
    void setPosition(pair<int,int> position);
    pair<int, int> getPosition();

};



#endif