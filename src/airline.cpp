#include "airline.hpp"
#include <vector>
#include <string>
using namespace std;

void airline::add_flight(const Flight& f){

}

const vector<Flight>& airline::get_flights() const{
    return flights;
}

const string& airline::get_name() const{
    return name;
}
