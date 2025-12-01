#include "../include/flight_class.hpp"
#include "../include/seat.hpp"
#include "../include/passenger.hpp"
#include "../include/route.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstddef>

using namespace std;


Flight::Flight(string ID, const Route& ROUTE, int ROWS, int SEATS_PER_ROW):id(ID),
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
    return &route;
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

    cout << "    ";
    char seatLetters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    for(int col = 0; col < seats_per_row; col++) {
        cout << seatLetters[col] << "   ";
    }
    cout << endl;
    
    cout << "  +";
    for(int col = 0; col < seats_per_row; col++) {
        cout << "---+";
    }
    cout << endl;
    
    for(int row = 0; row < rows; row++) {
        if(row < 10) {
            cout << row << " ";
        } else {
            cout << row;
        }
        
        for(int col = 0; col < seats_per_row; col++) {
            int seatIndex = row * seats_per_row + col;
            char status = seats[seatIndex]->getStatus();
            
            cout << "| ";
            if(status == 'O' || status == 'X') {
                cout << "X";
            } else {
                cout << " ";
            }
            cout << " ";
        }
        cout << "|" << endl;
        
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
    cout << "\nPassenger List (Flight:" << id << " from "
    << route.getSource() << " to " << route.getDestination()
    << ")\n";
        
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

const vector<Passenger*>& Flight::getPassengers() const {
    return passengers;
}

Flight::Flight(const Flight& other) 
    : id(other.id),
      route(other.route),
      rows(other.rows),
      seats_per_row(other.seats_per_row),
      passengers(other.passengers)
{
    seats.clear();
    for(size_t i = 0; i < other.seats.size(); i++) {
        if(other.seats[i] != nullptr) {
            seats.push_back(new Seat(*other.seats[i]));
        } else {
            seats.push_back(nullptr);
        }
    }
}

Flight& Flight::operator=(const Flight& other) {
    if(this != &other) {
        for(size_t i = 0; i < seats.size(); i++) {
            delete seats[i];
        }
        seats.clear();
        
        id = other.id;
        route = other.route;
        rows = other.rows;
        seats_per_row = other.seats_per_row;
        passengers = other.passengers;
        
        for(size_t i = 0; i < other.seats.size(); i++) {
            if(other.seats[i] != nullptr) {
                seats.push_back(new Seat(*other.seats[i]));
            } else {
                seats.push_back(nullptr);
            }
        }
    }
    return *this;
}
