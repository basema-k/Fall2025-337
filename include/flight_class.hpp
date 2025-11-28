#ifndef flightClass_h
#define flightClass_h

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Seat;
class Passenger;
class Route;

class Flight
{
public:
    Flight(string ID, Route* ROUTE, int ROWS, int SEATS_PER_ROW);
    void addPassenger(Passenger* p);
    void updateSeatMap(const Seat* selectedSeat);
    void showSeatMap() const;

    string getID() const;
    int getRows() const;
    int getSeatsPerRow() const;
    const Route* getRoute() const;
    
private:
    string id;
    Route* route;
    int rows;
    int seats_per_row;

    vector<Seat*> seats;
    vector<Passenger*> passengers;
};

#endif