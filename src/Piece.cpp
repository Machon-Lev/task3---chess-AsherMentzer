#include "Piece.h"

Piece::Piece(bool white, Location location):_white(white),_location(location){}

Piece::~Piece(){}


bool Piece::getColor()
{
	return _white;
}

Location Piece::getLocation()
{
	return _location;
}

void Piece::setLocation(Location new_location)
{
	_location = new_location;
}
