#pragma once
#include "Piece.h"
#include "Location.h"

/*
* @brief Represents a Queen chess piece.
*/
class Queen :public Piece
{
public:
	Queen(bool player, Location location);
	~Queen();
	bool isValidMove(Location dst_location, Board* gameBoard);
	std::vector<Location> getAllValidMoves(Board* gameBoard) ;
};
