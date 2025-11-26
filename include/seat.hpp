#ifndef SEAT_HPP
#define SEAT_HPP

#include <string>
using namespace std;

class Seat {
private:
    int row;
    char letter;
    char status;

public:
    // constructors
    Seat();
    Seat(int r, char l, char s);
    Seat(const string& seatStatus);   

    // getters
    int getRow() const;
    char getLetter() const;
    string getSeatStatus() const;

    // setters
    void setRow(int r);
    void setLetter(char l);
    void setSeatStatus(const string& seatStr);

};

#endif


