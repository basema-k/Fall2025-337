#include "../include/flight_class.hpp"
#include "../include/seat.hpp"
#include "../include/passenger.hpp"
#include "../include/route.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstddef>

using namespace std;


Flight::Flight(string ID, Route* ROUTE, int ROWS, int SEATS_PER_ROW):id(ID),
route(ROUTE),rows(ROWS),seats_per_row(SEATS_PER_ROW) {
    char seatLetters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < SEATS_PER_ROW; col++) {
            Seat* seat = new Seat(row, seatLetters[col], 'F');
            seats.push_back(seat);
        }
    }
    
}

int Flight::getRows() const{
    return rows;
}
int Flight::getSeatsPerRow() const{
    return seats_per_row;
}

void Flight::addPassenger(Passenger* passenger){
    passengers.push_back(passenger);
    updateSeatMap(passenger->getSeat());
}

string Flight::getID() const{
    return id;
}

const Route* Flight::getRoute() const{
    return route;
}

void Flight::updateSeatMap(const Seat* selectedSeat){
    for(size_t i = 0; i < seats.size(); i++){
        if((seats.at(i)->getRow() == selectedSeat->getRow()) && 
           (seats.at(i)->getLetter() == selectedSeat->getLetter())) {
            seats.at(i)->setStatus('O');
        }
    }
}

void Flight::showSeatMap() const {
    cout << "Aircraft Seat Map for flight " << id << endl;
    
    // Print column headers (seat letters)
    cout << "    ";
    char seatLetters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    for(int col = 0; col < seats_per_row; col++) {
        cout << seatLetters[col] << "   ";
    }
    cout << endl;
    
    // Print separator line
    cout << "  +";
    for(int col = 0; col < seats_per_row; col++) {
        cout << "---+";
    }
    cout << endl;
    
    // Print each row
    for(int row = 0; row < rows; row++) {
        // Print row number
        if(row < 10) {
            cout << row << " ";
        } else {
            cout << row;
        }
        
        // Print seats for this row
        for(int col = 0; col < seats_per_row; col++) {
            int seatIndex = row * seats_per_row + col;
            char status = seats[seatIndex]->getStatus();  // Changed to char and getStatus
            
            cout << "| ";
            if(status == 'O' || status == 'X') {  // Compare with char, not string
                cout << "X";
            } else {
                cout << " ";
            }
            cout << " ";
        }
        cout << "|" << endl;
        
        // Print separator line
        cout << "  +";
        for(int col = 0; col < seats_per_row; col++) {
            cout << "---+";
        }
        cout << endl;
    }
}

Flight::~Flight() {
    for(size_t i = 0; i < seats.size(); i++) {
        delete seats[i];
    }
}

void Flight::displayPassengers() const {
    cout << "\nPassenger List (Flight:" << id << " from ";
    if(route) {
        cout << route->getSource() << " to " << route->getDestination();
    }
    cout << ")\n" << endl;
    
    cout << "First Name    Last Name     Phone            Row  Seat  ID" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    
    for(size_t i = 0; i < passengers.size(); i++) {
        const Seat* seat = passengers[i]->getSeat();
        
        cout << passengers[i]->getFirstName();
        for(size_t space = passengers[i]->getFirstName().length(); space < 14; space++) {
            cout << " ";
        }
        
        cout << passengers[i]->getLastName();
        for(size_t space = passengers[i]->getLastName().length(); space < 14; space++) {
            cout << " ";
        }
        
        cout << passengers[i]->getPhoneNumber();
        for(size_t space = passengers[i]->getPhoneNumber().length(); space < 17; space++) {
            cout << " ";
        }
        
        cout << seat->getRow() << "    " 
             << seat->getLetter() << "     " 
             << passengers[i]->getIDNumber() << endl;
    }
    cout << "------------------------------------------------------------------------" << endl;
}
