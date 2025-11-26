#ifndef AIRLINE_HPP
#define AIRLINE_HPP

#include "flight.hpp"
#include <vector>
#include <string>
using namespace std;


class airline
{
    private:
    vector<Flight> flights;
    string name;

    public:
    airline();
    void add_flight(const Flight& f);

    // Getters
    const vector<Flight>& get_flights() const;
    const string& get_name() const;

};

#endif