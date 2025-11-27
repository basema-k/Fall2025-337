#ifndef ROUTE_HPP
#define ROUTE_HPP
#include <vector>
#include <string>
using namespace std;

class route
{

private:
    string source;
    string destination;

public:

    route(const string& src, const string& dest);
    
    // Getters
    string getSource() const; 
    string getDestination() const;
};


#endif
