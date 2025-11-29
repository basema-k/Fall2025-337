#include "../include/airline.hpp"
#include "../include/route.hpp"
#include <iomanip>
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

static int safe_stoi(const string& field){    
    try {
        size_t pos = 0;
        int v = stoi(field, &pos);
        if (pos != field.size()) return 0;
        return v;
    }catch(...){
        return 0;
    }
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
        if (!line.empty() && line.back() == '\r') line.pop_back();

        stringstream ss(line);
        string field;
        string id, src, dest;
        int rows = 0, seats = 0;
        int col = 0;

        while(getline(ss, field, ',')){
        switch(col){
            case 0: id = field; break;
            case 1: src = field; break;            
            case 2: dest = field; break;            
            case 3: rows = safe_stoi(field); break;            
            case 4: seats = safe_stoi(field); break;
            default: break;

        }
        ++col;
    }

    if (col < 5) {
        cerr << "Skipping malformed line: " << line << endl;
        continue;
    }
      
    Route r(src, dest);
    Flight f(id, r, rows, seats);
    add_flight(f);
    }
}

