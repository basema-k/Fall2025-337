#include "route.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

route::route(const string& src, const string& dest){
    route::source = src;
    route::destination = dest;

}

string route::getSource() const{
    return source;
}
    
string route::getDestination() const{
    return destination;
}