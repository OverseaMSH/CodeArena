#include "UserMenu.h"   // UserMenu class definition and implementation which includes the menu and user choice
#include <iostream>     // input/output operations (cin, cout)
#include <limits>       // Wrong input handling
#include <chrono>       // Time handling
#include <thread>       // Sleep function
#include <cstdlib>      // System function
#ifdef _WIN32
#include <windows.h>    // Windows-specific library for terminal size
#else
#include <sys/ioctl.h>  // Linux/Mac-specific for terminal size
#include <unistd.h>     // Unix standard library
#endif
#include <string>       // String handling

using namespace std;

// Function to get terminal width and height dynamically
void getTerminalSize(int& width, int& height) {
    width = 80;  // Default width
    height = 24; // Default height
#ifdef _WIN32
    // Windows-specific way to get terminal size
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
#else
    // Unix/Linux/Mac way to get terminal size
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        width = w.ws_col;
        height = w.ws_row;
    }
#endif
}

// Function to center text based on terminal width
string centerText(const string& text, int width) {
    int padding = (width - text.length()) / 2;
    return string(padding > 0 ? padding : 0, ' ') + text;
}

// Function to center the menu vertically and horizontally
void UserMenu::displayUserMenu() {
    int terminalWidth, terminalHeight;
    getTerminalSize(terminalWidth, terminalHeight);  // Get current terminal width and height

    int menuHeight = 4; // Number of lines in the menu
    int verticalPadding = (terminalHeight - menuHeight) / 2; // Calculate how many blank lines are needed to center vertically

    // Print vertical padding (blank lines)
    for (int i = 0; i < verticalPadding; i++) {
        cout << endl;
    }

    // Center-align each line of the menu horizontally
    cout << centerText("Welcome to the System", terminalWidth) << endl;  
    cout << centerText("1. Login", terminalWidth) << endl;
    cout << centerText("2. Register", terminalWidth) << endl;
    cout << centerText("3. Exit", terminalWidth) << endl;
}

int UserMenu::getUserChoice() {
    string input;
    int choice;

    while (true) {
        displayUserMenu();  // Show UserMenu
        int terminalWidth, terminalHeight;
        getTerminalSize(terminalWidth, terminalHeight);  // Get current terminal width for input prompt
        cout << centerText("Enter your choice (1-3): ", terminalWidth);  // Center the input prompt
        getline(cin, input);  // Using getline to detect empty input

        // Check for empty input
        if (input.empty()) {
            cout << centerText("Input cannot be empty. Please enter a valid choice.", terminalWidth) << endl;
            
            // Wait for 3 seconds
            this_thread::sleep_for(chrono::seconds(3));

            // Clear the terminal
            #ifdef _WIN32
                system("cls");  // Windows
            #else
                system("clear");  // Linux and Mac
            #endif

            continue;  // Repeat loop to get valid input
        }

        // Convert string input to an integer
        try {
            choice = stoi(input);  // Convert input to an integer

            if (choice < 1 || choice > 3) {  // If input is out of range
                cout << centerText("Invalid choice. Please choose between 1 and 3.", terminalWidth) << endl;

                // Wait for 3 seconds
                this_thread::sleep_for(chrono::seconds(3));

                // Clear the terminal
                #ifdef _WIN32
                    system("cls");  // Windows
                #else
                    system("clear");  // Linux and Mac
                #endif
            } else {
                return choice;  // Return the valid choice
            }
        } catch (exception &e) {  // Handle error if input is not a valid number
            cout << centerText("Invalid input. Please enter a number.", terminalWidth) << endl;

            // Wait for 3 seconds
            this_thread::sleep_for(chrono::seconds(3));

            // Clear the terminal
            #ifdef _WIN32
                system("cls");  // Windows
            #else
                system("clear");  // Linux and Mac
            #endif
        }
    }
}
