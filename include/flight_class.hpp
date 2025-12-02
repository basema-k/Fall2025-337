#ifndef FLIGHT_CLASS_HPP
#define FLIGHT_CLASS_HPP

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
    
    // Add these:
    Flight(const Flight& other);  // Copy constructor
    Flight& operator=(const Flight& other);  // Copy assignment operator
    
    void addPassenger(Passenger* p);
    void updateSeatMap(const Seat* selectedSeat);
    void showSeatMap() const;
    void displayPassengers() const;

    string getID() const;
    int getRows() const;
    int getSeatsPerRow() const;
    const Route* getRoute() const;
    const vector<Passenger*>& getPassengers() const; // Add this
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