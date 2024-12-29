#pragma once
#include <vector>
#include <string>
#include <iostream>

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
#define GREY "\033[0;90m"     //
#define ORANGE "\033[38;5;214m" 

using namespace std;

class DesignStructs 
{
    public:

    struct Header 
    {

        vector<string> text =
        {
         
        YELLOW R"(  _____ _          _  _____            )",
        ORANGE R"( |  __ (_)        | |/ ____|           )",
        CYAN R"( | |__) |__  _____| | |  __  ___ _ __  )",
        BLUE R"( |  ___/ \ \/ / _ \ | | |_ |/ _ \ '_ \ )",
        GREEN R"( | |   | |>  <  __/ | |__| |  __/ | | |)",
        RED R"( |_|   |_/_/\_\___|_|\_____|\___|_| |_|)",RESET,
        MAGENTA R"(By Patrick Miller)",RESET
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
        {   "Use arrow keys to navigate array of pixels",
            "Press 'Esc' to quit at any time.",
            ""
            "Please Select from the following colors: ",
            "------------------------------------------",
            "1. Red         7. White",
            "2. Orange      8. Black",
            "3. Yellow      9. Cyan ",
            "4. Green       0. Grey ",
            "5. Blue",
            "6. Magenta             "
        };
        void print() {
            for (string line : text) {
                cout << line << endl;
            }
        }
    };


    struct Quit
    {
        vector<string> text =
        {
        "Would you like to quit?",
        "------------------------------------------",
        "'Y' to quit",
        "'N' to continue"

        };
            void print() {
            for (string line : text) {
                cout << line << endl;
            }
        }


    };

    Quit QuitStruct;
    Header HeaderStruct;
    Default DefaultStruct;
};


                                       
                                       
  
 