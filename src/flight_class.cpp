#include "flight_class.h"
#include <iostream>
using namespace std;

Flight::Flight(string ID, Route* ROUTE, int ROWS, int SEATS_PER_ROW):id(ID), route(ROUTE),rows(ROWS),seats_per_row(SEATS_PER_ROW){
    
}

int Flight::getRows() const{
    return rows;
}
int Flight::getSeatsPerRow() const{
    return seats_per_row;
}

void Flight::addPassenger(Passenger* passenger){
    passengers.push_back(passenger);
}

string Flight::getID() const{
    return id;
}

const Route* Flight::getRoute() const{
    return route;
}