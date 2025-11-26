#ifndef SEAT_HPP
#define SEAT_HPP

#include <string>
using namespace std;

class Seat {
private:
    int row;
    char letter;

public:
    // constructors
    Seat();
    Seat(int r, char l);
    Seat(const string& seatStr);   

    // getters
    int getRow() const;
    char getLetter() const;
    string getSeatString() const;

    // setters
    void setRow(int r);
    void setLetter(char l);
    void setSeat(const string& seatStr);

};

#endif

