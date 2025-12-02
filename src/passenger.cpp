#include "../include/passenger.hpp"
#include "../include/seat.hpp"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Passenger::Passenger()
    : flight_id(""),
      first_name(""),
      last_name(""),
      phone_number(""),
      seat(),
      id_number(0) {}

Passenger::Passenger(const string& flight,
                     const string& fn,
                     const string& ln,
                     const string& phone,
                     const Seat& seatObj,
                     int id)
                    : flight_id(flight),
                    first_name(fn),
                    last_name(ln),
                    phone_number(phone),
                    seat(seatObj),
                    id_number(id) {}

void Passenger::setFlightID(const string& id) {
    flight_id = id;
}

void Passenger::setFirstName(const string& fn) {
    first_name = fn;
}

void Passenger::setLastName(const string& ln) {
    last_name = ln;
}

void Passenger::setPhoneNumber(const string& phone) {
    phone_number = phone;
}

void Passenger::setSeat(const Seat& s) {
    seat = s;
}

void Passenger::setIDNumber(int id) {
    id_number = id;
}

// getters
string Passenger::getFlightID() const {
    return flight_id;
}

string Passenger::getFirstName() const {
    return first_name;
}

string Passenger::getLastName() const {
    return last_name;
}

string Passenger::getPhoneNumber() const {
    return phone_number;
}

const Seat* Passenger::getSeat() const {
    return &seat;
}

int Passenger::getIDNumber() const {
    return id_number;
}

vector<Passenger*> Passenger::inputPassengers(){
    vector<Passenger*> passengers;
    
    ifstream in_stream("input/passengers.txt");
    if(in_stream.fail()){
        cout<<"Error opening the passenger.txt file..."<<endl;
        return passengers;
    }
    
    string line;

    while(getline(in_stream, line)){
        if(line.empty())
            continue;
        string flightid, first, last, phone, seat;
        int idnum;
        stringstream ss(line); 

        ss >> flightid >> first >> last >> phone >> seat >> idnum;
        if (ss.fail()) { 
            cout << "Skipping invalid line: " << line << endl;
            continue;
        }
        Seat s;

        if (seat.length() >= 2) {
            int row = stoi(seat.substr(0, seat.length() - 1));
            char letter = seat.back();
            s.setRow(row);
            s.setLetter(letter);
            s.setStatus('O');
        }

        Passenger* p = new Passenger(flightid, first, last, phone, s, idnum);
        passengers.push_back(p);
    }
    return passengers;
}

void Passenger::deletePassenger(vector<Passenger*>& passengers, const string& flightID){
    int removeID;
    cout << "Enter the passenger ID to remove: ";
    cin >> removeID;


    for(size_t i = 0; i < passengers.size(); i++){
        Passenger* p = passengers[i];

        if(p->getFlightID() == flightID && p->getIDNumber() == removeID){
            cout << "Removing pasenger: " << p->getFirstName() << " " << p->getLastName() << endl;
            delete p;
            passengers.erase(passengers.begin()+i);

            cout << "Passenger removed!" << endl;
            return;
        }
    }
    cout << "Passenger ID not found on this flight";
    return;

}







