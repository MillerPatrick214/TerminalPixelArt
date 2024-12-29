#include "Board.h"
#include <array>
#include <iostream>


using namespace std;

Board::Board() {
    cout << "Please enter canvas size: " << endl;
    cin >> boardSize;


    for (int i = 0; i < boardSize; ++i) {

        vector<Pixel*> row;
        for (int j = 0; j < boardSize; ++j) {
            row.push_back(new Pixel(i, j));
        }
        pixelVect.push_back(row);
    }

    currPixel = pixelVect[0][0];
    currPixel->setSelected(true);
}

void Board::clearBoard() {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            delete pixelVect[i][j];
            pixelVect[i][j] = nullptr;
        }
    }
}

void Board::printBoard() {

    cout << endl;
    cout << "Coords: " << currPixel->getPosition().first + 1 << ", " << currPixel->getPosition().second + 1<< endl;
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            pixelVect[i][j]->printVisualPixel();

        }
        cout << endl;
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


    currPixel->setSelected(false);      //set old pixel to selected=false
    currPixel = pixelVect[newX][newY];  //new curPix assigned
    currPixel->setSelected(true);       //new currPix set selected which enables flash
}
Pixel* Board::getCurrPixel() {
    return currPixel; 
}