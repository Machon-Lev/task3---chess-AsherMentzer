#pragma once
#include "Piece.h"
#include "Location.h"

/*
* @brief Represents a Knight chess piece.
*/
class Knight :public Piece
{
public:
	Knight(bool player, Location location);
	~Knight();
	bool isValidMove(Location dst_location, Board* gameBoard);
	std::vector<Location> getAllValidMoves(Board* gameBoard);
};
