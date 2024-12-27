#ifndef UI_H
#define UI_H

#include <utility>
#include "Board.h"
#include <string>

using namespace std;

class UI {
private:
    pair<int,int> cursorPosition;
    Board pixelBoard;

public:
    class InputError : public exception {
    public:
        const char* what() const noexcept override {
            return "Error: Input not recognized";
        }
    };


   void beginProgram();        //Starts program loop
   string inputPoll();       //now that we can compile & use on windows, we can do actual input polling.
   void processInput(string inputEvent);        //will need something passed to it, likely a string w/ map;
   //void displayBoard();        //invokes boardObject to print, which then prints each indivual pixel
   //void moveCursor();          // called when an input to move the cursor is detected during polling
    //void selectPixel();         //called when enter is hit while cursor is over an individual pixel 
    //void selectColor();         //eehh
};



#endif 