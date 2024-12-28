#ifndef UI_H
#define UI_H

#include <utility>
#include "Board.h"
#include <string>
#include "DesignStructs.h"

using namespace std;

class UI {
private:
    pair<int, int> uiCursorPosition; //Maybe should have cursor position for UI, and another pixelCursPosition for board
    Board pixelBoard;
    string currScreen;
    DesignStructs TextStructs;


public:
    class InputError : public exception {
    public:
        const char* what() const noexcept override {
            return "Error: Input not recognized";
        }
    };
   void printScreen(string currBottom);
   void beginProgram();        //Starts program loop
   string inputPoll();       //now that we can compile & use on windows, we can do actual input polling.
   void processInput(string inputEvent, bool& quitting);        //will need something passed to it, likely a string w/ map;
   bool quit();
   //void setCurrScreen(string currScreen);
   //string getCurrScreen();
   //void displayBoard();        //invokes boardObject to print, which then prints each indivual pixel
   //void moveCursor();          // called when an input to move the cursor is detected during polling
   //void selectPixel();         //called when enter is hit while cursor is over an individual pixel 
   //void selectColor();         //eehh
};



#endif 