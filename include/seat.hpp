#ifndef SEAT_HPP
#define SEAT_HPP

#include <string>
using namespace std;

class Seat {
private:
    int row;
    char letter;    
    char status;    // F : free, O : occupied

public:
    // default constructor
    Seat() : row(0), letter('A'), status('F') {}

    // general constructor 
    Seat(int r, char l, char s = 'F')
        : row(r), letter(l), status(s) {}

    // getters
    int getRow() const {return row;}
    char getLetter() const {return letter;}
    char getStatus() const {return status;}

    // setters
    void setRow(int r) {row = r;}
    void setLetter(char l) {letter = l;}
    void setStatus(char s) {status = s;}
};

#endif
