#include "../include/route.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

Route::Route(const string& src, const string& dest)
    : source(src), destination(dest) {
}

string Route::getSource() const{ 
    return source;
}
    
string Route::getDestination() const{
    return destination;
}