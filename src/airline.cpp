#include "../include/airline.hpp"
#include "../include/route.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <cstddef> 

using namespace std;

airline::airline(): airline_name(""){

}

airline::airline(const string& name):airline_name(name){

}

void airline::add_flight(const Flight& f){

    string airline_id = f.getID();
    for (size_t i = 0; i < flights.size(); i++){
        string old_flights = flights[i].getID();
        if (airline_id == old_flights){
            return;
        }
    }
    flights.push_back(f);
}

void airline::remove_flight(const string& ID){
    for (size_t i = 0; i < flights.size(); i++){
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

void airline::loadFlights(const string& filename){
    ifstream data(filename); 
    if (!data.is_open()) {
        cerr << "Error: cannot open file '" << filename << "'." << endl;
        return;
    }

    string line;

    while (getline(data,line)) {
        if (line.empty()) continue; // Skip blank lines

        stringstream ss(line);
        string id;
        string src;
        string dest;
        string str_rows;
        string str_seats;
        int rows;
        int seats;

        getline(ss, id, ',');
        getline(ss, src, ',');
        getline(ss, dest, ',');
        getline(ss, str_rows, ',');
        getline(ss, str_seats, ',');

        rows = stoi(str_rows);
        seats = stoi(str_seats);

        Route r(src, dest);

        Flight f(id, r, rows, seats);

        add_flight(f);


}
        data.close();

}