#include "../include/Seat.hpp"
#include <string>
using namespace std;

// default constructor
Seat::Seat()
    : row(0), letter('A'), status('F')   // F : Free seat
{
}

// general constructor
Seat::Seat(int r, char l, char s)
    : row(r), letter(l), status(s)
{
}

// getters
int Seat::getRow() const {
    return row;
}

char Seat::getLetter() const {
    return letter;
}

char Seat::getSeatStatus() const {
    return status;
}

// setters
void Seat::setRow(int r) {
    row = r;
}

void Seat::setLetter(char l) {
    letter = l;
}

void Seat::setSeatStatus(char s) {
    status = s;
}
