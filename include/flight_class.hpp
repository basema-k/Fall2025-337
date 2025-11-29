#ifndef flightClass_h
#define flightClass_h

#include <vector>
#include <string>
#include <iostream>
#include "../include/route.hpp"
using namespace std;

class Seat;
class Passenger; 

class Flight
{
public:
    Flight(string ID, const Route& ROUTE, int ROWS, int SEATS_PER_ROW);
    void addPassenger(Passenger* p);
    void updateSeatMap(const Seat* selectedSeat);
    void showSeatMap() const;
    void displayPassengers() const;

    string getID() const;
    int getRows() const;
    int getSeatsPerRow() const;
    const Route* getRoute() const;
    ~Flight();
    
private:
    string id;
    Route route;
    int rows;
    int seats_per_row;
    vector<Seat*> seats;
    vector<Passenger*> passengers;
};


#endif