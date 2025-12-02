#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "../include/flight_class.hpp"
#include "../include/passenger.hpp"
#include "../include/seat.hpp"
#include "../include/airline.hpp"
#include "../include/route.hpp"

using namespace std;

void menu_choice(int& choice);
void load_passengers(airline& myAirline, const string& filename);
void save_data(airline& myAirline, const string& filename);

int main() {
    airline myAirline("WestJet");
    
    myAirline.loadFlights("flights.csv");
    load_passengers(myAirline, "input/passengers.txt");

    cout << "Version: 1.0\n";
    cout << "Term Project - Flight Management Program in C++\n";
    cout << "Produced by: Ayman, Basema and Azlan\n"; 
    cout << "Year: 2025\n";
    cout << "\n<<< Press Return to Continue >>>";
    
    cin.get();
    
    int choice;
    Flight* currentFlight = nullptr; 

    do {
        menu_choice(choice);

        switch(choice) {
            case 1: { 
                myAirline.displayFlights();
                cout << "Enter your choice: ";
                int flightIndex;
                cin >> flightIndex;

                const vector<Flight>& flights = myAirline.get_flights();
                if(flightIndex > 0 && flightIndex <= (int)flights.size()) {
                    currentFlight = const_cast<Flight*>(&flights[flightIndex - 1]);
                    const Route* r = currentFlight->getRoute();
                    cout << "You have selected flight " << currentFlight->getID() 
                         << " from " << r->getSource() 
                         << " to " << r->getDestination() << "." << endl;
                } else {
                    cout << "Invalid flight selection. Please try again." << endl;
                }
                break;
            }
            case 2: 
                if(currentFlight == nullptr) {
                    cout << "Please select a flight first (Option 1)." << endl;
                } else {
                    currentFlight->showSeatMap(); 
                }
                break;
            case 3: 
                if(currentFlight == nullptr) {
                    cout << "Please select a flight first (Option 1)." << endl;
                } else {
                    currentFlight->displayPassengers();
                }
                break;
            case 4: { 
                if(currentFlight == nullptr) {
                    cout << "Please select a flight first (Option 1)." << endl;
                } else {
                    int id, row;
                    string fname, lname, phone;
                    char seatChar;

                    cout << "Please enter the passenger id: ";
                    cin >> id;
                    cin.ignore();
                    cout << "Please enter the passenger first name: ";
                    cin >> fname;
                    cout << "Please enter the passenger last name: ";
                    cin >> lname;
                    cout << "Please enter the passenger phone number: ";
                    cin >> phone;
                    cout << "Enter the passenger's desired row: ";
                    cin >> row;
                    cout << "Enter the passenger's desired seat: ";
                    cin >> seatChar;

                    if(row < 0 || row >= currentFlight->getRows()) {
                        cout << "Error: Invalid row number. Must be between 0 and " << (currentFlight->getRows() - 1) << "." << endl;
                        break;
                    }

                    if(seatChar < 'A' || seatChar >= ('A' + currentFlight->getSeatsPerRow())) {
                        cout << "Error: Invalid seat letter. Must be between A and " << (char)('A' + currentFlight->getSeatsPerRow() - 1) << "." << endl;
                        break;
                    }

                    const vector<Passenger*>& existingPassengers = currentFlight->getPassengers();
                    bool duplicateID = false;
                    for(const Passenger* p : existingPassengers) {
                        if(p->getIDNumber() == id) {
                            cout << "Error: Passenger ID already exists on this flight." << endl;
                            duplicateID = true;
                            break;
                        }
                    }
                    if(duplicateID) break;

                    bool seatTaken = false;
                    for(const Passenger* p : existingPassengers) {
                        if(p->getSeat()->getRow() == row && p->getSeat()->getLetter() == seatChar) {
                            cout << "Error: Seat already occupied." << endl;
                            seatTaken = true;
                            break;
                        }
                    }
                    if(seatTaken) break;

                    Seat s(row, seatChar);
                    Passenger* newP = new Passenger(currentFlight->getID(), fname, lname, phone, s, id);
                    
                    currentFlight->addPassenger(newP); 
                    currentFlight->updateSeatMap(&s);
                    cout << "Passenger added successfully." << endl;
                }
                break;
            }
            case 5: { 
                if(currentFlight == nullptr) {
                    cout << "Please select a flight first (Option 1)." << endl;
                } else {
                    int id;
                    cout << "Please enter the id of the passenger that needs to be removed: ";
                    cin >> id;
                    
                    vector<Passenger*>& passengers = const_cast<vector<Passenger*>&>(currentFlight->getPassengers());
                    bool found = false;
                    
                    for(size_t i = 0; i < passengers.size(); i++) {
                        if(passengers[i]->getIDNumber() == id) {
                            delete passengers[i];
                            passengers.erase(passengers.begin() + i);
                            cout << "Passenger removed successfully." << endl;
                            found = true;
                            break;
                        }
                    }
                    
                    if(!found) {
                        cout << "Error: Passenger ID not found on this flight." << endl;
                    }
                }
                break;
            }
            case 6: { 
                char confirm;
                cout << "Do you want to save the data in the \"passengers.txt\"? Please answer <Y or N> ";
                cin >> confirm;
                if(confirm == 'Y' || confirm == 'y') {
                    save_data(myAirline, "input/passengers.txt");
                    cout << "All the data in the passenger list were saved." << endl;
                }
                break;
            }
            case 7: 
                cout << "Program terminated." << endl;
                break;
        }

        if(choice != 7) {
            cout << "\n<<< Press Return to Continue >>>";
            cin.ignore(10000, '\n'); 
            cin.get();
        }

    } while(choice != 7);

    return 0;
}

void menu_choice(int& choice){
    cout << "\nPlease select one the following options:\n" << endl;
    cout << "1. Select a flight" << endl;
    cout << "2. Display Flight Seat Map." << endl;
    cout << "3. Display Passengers Information." << endl;
    cout << "4. Add a New Passenger." << endl;
    cout << "5. Remove an Existing Passenger" << endl;
    cout << "6. Save data" << endl;
    cout << "7. Quit." << endl;
    cout << "\nEnter your choice: (1, 2, 3, 4, 5, 6, or 7) ";

    while(true){
        cin >> choice;
        if(cin.fail()||choice<1||choice>7){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid input. Please enter a number between 1 and 7: ";
        } else {
            break;
        }
    }
}

void load_passengers(airline& myAirline, const string& filename) {
    ifstream infile(filename);
    if(!infile.is_open()) {
        return;
    }

    string flightID, fname, lname, phone, seatStr;
    int passID;

    while(infile >> flightID >> fname >> lname >> phone >> seatStr >> passID) {
        const vector<Flight>& flights = myAirline.get_flights();
        Flight* targetFlight = nullptr;
        
        for(const Flight& f : flights) {
            if(f.getID() == flightID) {
                targetFlight = const_cast<Flight*>(&f);
                break;
            }
        }

        if(targetFlight) {
            char seatChar = seatStr.back();
            int row = stoi(seatStr.substr(0, seatStr.length() - 1));
            
            Seat s(row, seatChar);
            Passenger* p = new Passenger(flightID, fname, lname, phone, s, passID);
            
            targetFlight->addPassenger(p);
            targetFlight->updateSeatMap(&s);
        }
    }
    infile.close();
}

void save_data(airline& myAirline, const string& filename) {
    ofstream outfile(filename);
    if(!outfile.is_open()) {
        return;
    }
    
    const vector<Flight>& flights = myAirline.get_flights();
    
    for(const Flight& f : flights) {
        const vector<Passenger*>& passengers = f.getPassengers();
        
        for(const Passenger* p : passengers) {
            const Seat* seat = p->getSeat();
            string seatStr = to_string(seat->getRow()) + seat->getLetter();
            
            outfile << f.getID() << "\t"
                    << p->getFirstName() << "\t"
                    << p->getLastName() << "\t"
                    << p->getPhoneNumber() << "\t"
                    << seatStr << "\t"
                    << p->getIDNumber() << endl;
        }
    }
    
    outfile.close();
}