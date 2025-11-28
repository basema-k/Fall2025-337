#include <iostream>
#include "include/flight_class.hpp"
#include "include/passenger.hpp"
#include "include/seat.hpp"
#include "include/airline.hpp"
#include "include/route.hpp"

using namespace std;

void menu_choice(int& choice);  // Fixed declaration

int main() {
    cout << "Version: 1.0\n";
    cout << "Term Project - Flight Management Program in C++\n";
    cout << "Produced by: ---\n";
    cout << "Year: 2025\n";
    cout << "\n<<< Press Return to Continue >>>\n" << endl;
    
    cin.get();
    
    int choice;
    do {
        menu_choice(choice);
        cout << choice;

        


    } while(choice != 7);

    return 0;
}

void menu_choice(int& choice){
    cout << "\nPlease select one the following options:\n" << endl;
    cout << "1. Select a flight\n";
    cout << "2. Display Flight Seat Map.\\\n";
    cout << "3. Display Passengers Information.\n";
    cout << "4. Add a New Passenger.\n";
    cout << "5. Remove an Existing Passenger\n";
    cout << "6. Save data\n";
    cout << "7. Quit.\n" << endl;
        
    cout << "Enter your choice: (1, 2, 3, 4, 5, 6, or 7) ";

    while(true){
        cin >> choice;
        if(cin.fail()||choice<1||choice>7){
            cin.clear();
            cin.ignore();
            cout << "\nInvalid input. Please enter a number between 1 and 7: ";
        } else {
            cin.ignore();
            break;
        }
    }
    
}