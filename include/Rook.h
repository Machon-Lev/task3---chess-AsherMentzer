#pragma once
#include "Piece.h"
#include "Location.h"

/*
* @brief Represents a Roook chess piece.
*/
class Rook:public Piece
{
public:
	Rook(bool player,Location location);
	~Rook();
	bool isValidMove(Location dst_location, Board* gameBoard) ;
	std::vector<Location>getAllValidMoves(Board* gameBoard) ;
};

