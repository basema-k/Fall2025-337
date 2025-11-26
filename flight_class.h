
#ifndef flightClass_h
#define flightClass_h

#include <vector>
#include <string>
using namespace std;


class Seat;
class Passenger;
class Route;

class Flight
{
public:
    Flight(string id, Route route, int rows, int seats_per_row);
    void addPassenger(Passenger* p);

    string getID() const;
    int getRows() const;
    int getSeatsPerRow() const;
    
private:
    string id;
    Route* route;
    int rows;
    int seats_per_row;

    vector<Seat> seats;
    vector<Passenger> passengers;

};

#endif  