#include <string>
using namespace std;

include "Seat.hpp"

Seat::Seat(int r, char l, char s): row(r), letter(l), status(s)
{
}
int Seat::getRow()
{
	return row;
}
char Seat::getLetter()
{
	return letter;

char Seat::getSeatStatus()
{
	return status;
}
void Seat::setRow(int r)
{
	row = r;
}
void Seat::setLetter(char l)
{
	letter = l;
}
void Seat::setSeatStatus(char s)
{
	status = s;
}





