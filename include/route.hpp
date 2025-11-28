#ifndef ROUTE_HPP
#define ROUTE_HPP
#include <vector>
#include <string>
using namespace std;

class Route
{

private:
    string source;
    string destination;

public:

    Route(const string& src, const string& dest);
    
    string getSource() const; 
    string getDestination() const;
};


#endif
