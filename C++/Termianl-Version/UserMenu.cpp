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
    int choice;

    while (true) {
        displayUserMenu();  // Show UserMenu
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        if (cin.fail()) {  // Wrong input like string
            cin.clear();  //  Remove wrong input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Deny wrong input
            cout << "Invalid input. Please enter a number.\n";

            // Wait for 3 seconds
            this_thread::sleep_for(chrono::seconds(3));  

            // Clear Terminal
            #ifdef _WIN32
                system("cls");  // Windows
            #else
                system("clear");  // Linux and Mac
            #endif

        } else if (choice < 1 || choice > 3) {  //  Wrong input out of range
            cout << "Invalid choice. Please choose between 1 and 3.\n";

            // Wait for 3 seconds
            this_thread::sleep_for(chrono::seconds(3)); 

            // Clear Terminal
            #ifdef _WIN32
                system("cls");  // Windows
            #else
                system("clear");  // Linux and Mac
            #endif

        } else {
            return choice;  //  Return the correct choice
        }
    }
}
