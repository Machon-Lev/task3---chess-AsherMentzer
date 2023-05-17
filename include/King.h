#pragma once
#pragma once
#include "Piece.h"
#include "Location.h"
/**
 * @brief Represents a King chess piece.
 */
class King :public Piece
{
public:
	King(bool player, Location location);
	~King();
	bool isValidMove(Location dst_location,Board* gameBoard);
	std::vector<Location> getAllValidMoves(Board* gameBoard);
};
