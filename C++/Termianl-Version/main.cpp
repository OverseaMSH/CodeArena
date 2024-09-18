#include "UserMenu.h"  // UserMenu class definition and implementation which includes the menu and user choice
#include <iostream>    // input/output operations (cin, cout)
#include <chrono>       // Time handling
#include <thread>       // Sleep function
using namespace std;

int main() {
    UserMenu userMenu;

    while (true) {
        int choice = userMenu.getUserChoice();  // Get the user choice

        if (choice == 1) {
            string username, password;
            cout << "Enter username: ";  
            cin >> username;
            cout << "Enter password: ";  
            cin >> password;
        } else if (choice == 2) {
            string username, password;
            cout << "Enter username: ";  
            cin >> username;
            cout << "Enter password: ";  
            cin >> password;
        } else if (choice == 3) {
            cout << "Exiting...\n"; 
            this_thread::sleep_for(chrono::seconds(3)); 
            break;
        } else {
            cout << "Invalid choice, please try again.\n"; 
        }
    }

    return 0;
}
