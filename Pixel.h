#ifndef PIXEL_H
#define PIXEL_H

#include <string>
#include <utility>
#include <vector>


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

class Pixel {
 private:
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