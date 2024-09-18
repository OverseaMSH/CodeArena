#include "UserMenu.h"   // UserMenu class definition and implementation which includes the menu and user choice
#include <iostream>     // input/output operations (cin, cout)
#include <limits>       // Wrong input handling
#include <chrono>       // Time handling
#include <thread>       // Sleep function
#include <cstdlib>      // System function

using namespace std;

void UserMenu::displayUserMenu() {
    cout << "Welcome to the System\n";  
    cout << "1. Login\n";
    cout << "2. Register\n";
    cout << "3. Exit\n";
}

int UserMenu::getUserChoice() {
    string input;
    int choice;

    while (true) {
        displayUserMenu();  // Show UserMenu
        cout << "Enter your choice (1-3): ";
        getline(cin, input);  // Using getline to detect empty input

        // Check for empty input
        if (input.empty()) {
            cout << "Input cannot be empty. Please enter a valid choice.\n";
            
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
                cout << "Invalid choice. Please choose between 1 and 3.\n";

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
            cout << "Invalid input. Please enter a number.\n";

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
