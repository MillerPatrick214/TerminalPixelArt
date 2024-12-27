#include "Board.h"
#include <array>
#include <iostream>


using namespace std;

Board::Board() {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            pixelVect[i][j] = new Pixel(i, j);
        }
    }
    currPixel = pixelVect[0][0];
    currPixel->setSelected(true);
}

void Board::clearBoard() {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            delete pixelVect[i][j];
            pixelVect[i][j] = nullptr;
        }
    }
}

void Board::printBoard() {
    for (int i = 0; i < 20; ++i) {
        cout << endl;
        for (int j = 0; j < 20; ++i) {
            pixelVect[i][j]->printVisualPixel();
        }

    }
}

Pixel* Board::getPixel(int x, int y) {
    return pixelVect[x][y];
}

void Board::moveCursor(int x, int y) {                  //returns bool indicating a success or failure.
    pair<int, int> currCoords = currPixel->getPosition();

    int newX = currCoords.first + x;
    int newY = currCoords.second + y;

    if (newX < 0 || newX >= boardSize || newY < 0 || newY >= boardSize) {
        throw Board::BoundsError();
    }

    /*                                      //this needs to be put into a try catch block in the UI class. This function will throw the exception if necessary where it will be caught by that UI function
    catch (Board::BoundsError e) {
        cout << e.what() << endl;
        return
    }*/

    currPixel->setSelected(false);      //set old pixel to selected=false
    currPixel = pixelVect[newX][newY];  //new curPix assigned
    currPixel->setSelected(true);       //new currPix set selected which enables flash
}   