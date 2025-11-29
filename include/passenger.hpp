#ifndef PASSENGER_HPP
#define PASSENGER_HPP

#include <string>
#include <fstream>
#include <vector>
using namespace std;

#include "seat.hpp"

class Passenger {
private:
    string flight_id;     
    string first_name;
    string last_name;
    string phone_number;
    Seat seat;            // 'Seat' object
    int id_number;        

public:
    // default constructor
    Passenger();

    // general constructor (use when reading from text file)
    Passenger(const string& flight,
              const string& fn,
              const string& ln,
              const string& phone,
              const Seat& seatObj,
              int id);

    // setters
    void setFlightID(const string& id);
    void setFirstName(const string& fn);
    void setLastName(const string& ln);
    void setPhoneNumber(const string& phone);
    void setSeat(const Seat& s);
    void setIDNumber(int id);

    // getters
    string getFlightID() const;
    string getFirstName() const;
    string getLastName() const;
    string getPhoneNumber() const;
    const Seat* getSeat() const;
    int getIDNumber() const;

    // member functions
    static vector<Passenger*> inputPassengers();
    static void displayPassengers(vector<Passenger*>& passengers);
    void addPassenger(vector<Passenger*>& passengers, const string& flightID);
    void deletePassenger(const vector<Passenger*>& passengers, const string& flightID);

};

#endif
