#pragma once
#include <vector>
#include <string>
#include <iostream>


/*
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
*/
using namespace std;

class DesignStructs 
{
    public:

    struct Header 
    {

        vector<string> text =
        {
        "  _____ _          _  _____            "
        " |  __ (_)        | |/ ____|           ",
        " | |__) |__  _____| | |  __  ___ _ __  ",
        " |  ___/ \ \/ / _ \ | | |_ |/ _ \ '_ \ ",
        " | |   | |>  <  __/ | |__| |  __/ | | |",
        " |_|   |_/_/\_\___|_|\_____|\___|_| |_|"
        };

        void print() {
            for (string line : text) {
                cout << line << endl;
            }
        }
    };

    struct ColorSelect 
    {
        vector<string> text = 
        {
            "Please Select from the following colors: ",
            "-----------------------------------------",
            "1. Red     7. White",
            "2. Orange      8.Black",
            "3. Yellow      9. Cyan ",
            "4. Green       0. Return to pixel selection",
            "5. Blue"
            "6. Magenta"
        };
        void print() {
            for (string line : text) {
                cout << line << endl;
            }
        }
    };

    struct Default 
    {
        vector<string> text = 
        { 
            "Select Pixel"
            "------------------------------------------"
            "Use arrow keys to navigate array of pixels",
            "Hit 'Enter' to select pixel and choose color"
        };

        void print() {
            for (string line : text) {
                cout << line << endl;
            }
        }
    };

    Header HeaderStruct;
    Default DefaultStruct;
    ColorSelect Colorstruct;
};


                                       
                                       
  
 