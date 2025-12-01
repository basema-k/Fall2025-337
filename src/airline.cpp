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


void airline::loadFlights(const string& filename){
    ifstream data(filename); 
    if (!data.is_open()) {
        return;
    }

    string line;

    while (getline(data,line)) {
        if (line.empty()) continue;
        if (!line.empty() && line.back() == '\r')
            line.pop_back();

        stringstream ss(line);
        string field;
        string id, src, dest;
        int rows = 0, seats = 0;
        int col = 0;

        while(getline(ss, field, ',')) {
            size_t start = field.find_first_not_of(" \t");
            size_t end = field.find_last_not_of(" \t\r\n");
            if(start != string::npos && end != string::npos) {
                field = field.substr(start, end - start + 1);
            }

            if(col == 0) id = field;
            else if(col == 1) src = field;
            else if(col == 2) dest = field;
            else if(col == 3) rows = stoi(field);
            else if(col == 4) seats = stoi(field);
            col++;
        }

        if(!id.empty() && !src.empty() && !dest.empty() && rows > 0 && seats > 0) {
            Route r(src, dest);
            Flight f(id, r, rows, seats);
            add_flight(f);
        }
    }
    
    data.close();
}

void airline::displayFlights() const {
    cout << "Here is the list of available flights. Please select one:" << endl;
    for(size_t i = 0; i < flights.size(); i++) {
        const Flight& f = flights[i];
        const Route* r = f.getRoute();
        
        cout << (i + 1) << ". " 
             << left << setw(10) << f.getID() 
             << setw(15) << r->getSource() 
             << setw(15) << r->getDestination() 
             << setw(5) << f.getRows() 
             << setw(5) << f.getSeatsPerRow() << endl;
    }
}

