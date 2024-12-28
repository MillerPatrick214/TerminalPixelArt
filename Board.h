#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <array>
#include "Pixel.h"

using namespace std;
 
class Board {
  private:
      int boardSize = 20;
      array<array<Pixel*, 20>, 20>  pixelVect;
      Pixel* currPixel;
  
  public:
      Board();
      class BoundsError : public exception {
      public:
          const char* what() const noexcept override {
              return "Error: Cannot exceed bounds of board";
          }
      };
      void clearBoard(); //deletes each pixelvector pointer to nullptr
      void printBoard(); //calls each pixel in array to self print in the correct order;
      void moveCursor(int x, int y);
      Pixel* getPixel(int x, int y);
      Pixel* getCurrPixel();
};



#endif
