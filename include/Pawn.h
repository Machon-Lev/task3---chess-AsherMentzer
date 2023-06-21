#pragma once
#include "Piece.h"
#include "Location.h"

/*
* @brief Represents a Pawn chess piece.
*/
class Pawn :public Piece
{
public:
	Pawn(bool player, Location location);
	~Pawn();
	bool isValidMove(Location dst_location, Board* gameBoard);
	std::vector<Location> getAllValidMoves(Board* gameBoard);
private:
	bool _not_moved = true;
};
