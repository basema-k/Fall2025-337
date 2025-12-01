#include "../include/seat.hpp"
#include <string>
using namespace std;

Seat::Seat()
    : row(0), letter('A'), status('F')
{
}

Seat::Seat(int r, char l, char s)
    : row(r), letter(l), status(s)
{
}
int Seat::getRow() const {
    return row;
}

char Seat::getLetter() const {
    return letter;
}

char Seat::getStatus() const {
    return status;
}

void Seat::setRow(int r) {
    row = r;
}

void Seat::setLetter(char l) {
    letter = l;
}

void Seat::setStatus(char s) {
    status = s;
}
