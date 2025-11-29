#include "../include/passenger.hpp"
#include "../include/seat.hpp"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// deafult constructor
Passenger::Passenger()
    : flight_id(""),
      first_name(""),
      last_name(""),
      phone_number(""),
      seat(),              // call to default constructor for class "Seat"
      id_number(0) {}

// general constructor
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

// setters
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
    
    ifstream in_stream("passengers.txt");
    if(in_stream.fail()){
        cout<<"Error opening the passenger.txt file..."<<endl;
        return passengers; // returns empty vector if file fails to open
    }
    
    string line; // create a string to store each full line read from file

    while(getline(in_stream, line)){ // read entire line from file, and store into 'line'
        if(line.empty())
            continue; // skips blank lines
        string flightid, first, last, phone, seat;
        int idnum;
        stringstream ss(line); 

        ss >> flightid >> first >> last >> phone >> seat >> idnum; // reads text, attributes first string up till whitespace to flightid, moves to next element until all elements are accounted for
        if (ss.fail()) { 
            cout << "Skipping invalid line: " << line << endl;
            continue;
        }
        Seat s;

        if (seat.length() >= 2) {
            int row = stoi(seat.substr(0, seat.length() - 1)); // get integer portion of seat string (string to integer)
            char letter = seat.back(); // get character portion of seat string
            s.setRow(row);
            s.setLetter(letter);
            s.setStatus('O'); // seat will now be occupied
        }

        Passenger* p = new Passenger(flightid, first, last, phone, s, idnum);
        passengers.push_back(p);
    }
    return passengers;
}

void Passenger::displayPassengers(vector<Passenger*>& passengers){
    for (int i = 0; i < passengers.size(); i++) {
        const Passenger* p = passengers[i];
        const Seat* s = p->getSeat();

        cout << "First Name" << "Last Name" << "Phone" << "Row" << "Seat" << "ID" << endl;
        cout << p->getFirstName() << p->getLastName() << p->getPhoneNumber() << s->getRow() << s->getLetter() << p->getIDNumber() << endl;
    }
}

void Passenger::addPassenger(vector<Passenger*>& passengers, const string& flightID){
    string first, last, phone;
    int idnum, row;
    char seat;
    
    cout << "Please enter the passenger's id: " << endl;
    cin >> idnum;
    
    cout << "Please enter the passenger's first name: " << endl;
    cin >> first;
    
    cout << "Please enter the passenger's last name: " << endl;
    cin >> last;
    
    cout << "Please enter the passenger's phone number: " << endl;
    cin >> phone;
    
    cout << "Enter the passenger's desired row: " << endl;
    cin >> row;
    
    cout << "Enter the passenger's desired seat: " << endl;
    cin >> seat;

    for (int i = 0; i < passengers.size(); i++) {
        const Passenger* p = passengers[i];
        const Seat* s = p->getSeat();

        if(p->getFlightID() == flightID){
            if(p->getIDNumber() == idnum){
                cout << "Error: ID number already exists on this flight.";
                return;
            }
        
            if(s->getRow() == row && s->getLetter() == seat){
                cout << "Error: This seat is already taken.";
                return;
            }
        }
    }
    Seat newSeat(row, seat, 'O');
    Passenger* newPassenger = new Passenger(flightID, first, last, phone, newSeat, idnum);

    passengers.push_back(newPassenger);
    cout << "Passenger added successfully!" << endl;

}

void Passenger::deletePassenger(const vector<Passenger*>& passengers, const string& flightID){

}







