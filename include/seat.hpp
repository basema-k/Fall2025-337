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
    // Constructors
    Seat();
    Seat(int r, char l, char s = 'F');

    // Getters
    int getRow() const;
    char getLetter() const;
    char getStatus() const;

    // Setters
    void setRow(int r);
    void setLetter(char l);
    void setStatus(char s);
};

#endif
