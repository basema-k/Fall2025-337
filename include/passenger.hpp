#ifndef PASSENGERS
#define PASSENGERS

#include <string>
#include <iostream>
using namespace std;

class Passenger {
private:
    string flight_id;      
    string first_name;
    string last_name;
    string phone_number;
    Seat seat;           
    int id_number;         

public:
    // constructors
    Passenger();
    Passenger(const string& flight,
              const string& fn,
              const string& ln,
              const string& phone,
              const string& seat_value,
              int id);

    // setters
    void setFlightID(const string& id);
    void setFirstName(const string& fn);
    void setLastName(const string& ln);
    void setPhoneNumber(const string& phone);
    void setSeat(const string& seat_value);
    void setIDNumber(int id);

    // getters
    string getFlightID() const;
    string getFirstName() const;
    string getLastName() const;
    string getPhoneNumber() const;
    string getSeat() const;
    int getIDNumber() const;

};

#endif

