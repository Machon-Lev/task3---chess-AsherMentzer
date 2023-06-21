#pragma once
#include "Piece.h"
#include "Location.h"

/**
 * @brief Represents a bishop chess piece.
 */
class Bishop :public Piece{
public:
	Bishop(bool player, Location location);
	~Bishop();
	bool isValidMove(Location dst_location, Board* gameBoard);
	std::vector<Location> getAllValidMoves(Board* gameBoard);
};
