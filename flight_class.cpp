#include "flight_class.h"
#include <iostream>
using namespace std;

int Flight::getRows() const{
    return rows;
}
int Flight::getSeatsPerRow() const{
    return seats_per_row;
}