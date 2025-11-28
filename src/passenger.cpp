#include "../include/passenger.hpp"
#include "../include/seat.hpp"
#include <iostream>
#include <string>
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
