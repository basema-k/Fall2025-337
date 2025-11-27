#include "airline.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;



airline::airline(){
    airline_name = "";
}

airline::airline(const string& name){
    airline_name = name;
} 


void airline::add_flight(const Flight& f){

    string airline_id = f.getID();
    for (int i = 0; i < flights.size(); i++){
        string old_flights = flights[i].getID();
        if (airline_id == old_flights){
            return;
        }
    }
    flights.push_back(f);
}

void airline::remove_flight(const string& ID){
    for (int i = 0; i < flights.size(); i++){
        if (flights[i].getID() == ID){
             flights.erase(flights.begin() + i);
            return;
        }
    }

    }



const vector<Flight>& airline::get_flights() const{
    return flights;
}

const string& airline::get_name() const{
    return airline_name;
}
