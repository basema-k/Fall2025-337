#ifndef AIRLINE_HPP
#define AIRLINE_HPP

#include "../include/flight_class.hpp"
#include "../include/route.hpp"
#include <fstream>
#include <vector>
#include <string>
using namespace std;


class airline
{
    private:
    vector<Flight> flights;
    string airline_name;

    public:
    airline();
    airline(const string& name);
    void add_flight(const Flight& f);
    void remove_flight(const string& ID);
    void loadFlights(const string& filename);

    // Getters
    const vector<Flight>& get_flights() const;
    const string& get_name() const;

};

#endif