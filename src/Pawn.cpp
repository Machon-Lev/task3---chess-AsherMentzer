#include "..\include\Pawn.h"

Pawn::Pawn(bool player, Location location) :Piece(player, location){}

Pawn::~Pawn(){}

bool Pawn::isValidMove(Location dst_location, Board* gameBoard)
{
	std::vector<Location> valid_moves = getAllValidMoves(gameBoard);
	if (std::find(valid_moves.begin(), valid_moves.end(), dst_location) == valid_moves.end())
		return false;
	return true;
}

std::vector<Location> Pawn::getAllValidMoves(Board* gameBoard)
{
	std::vector<Location> valid_moves = std::vector<Location>();
	int row_direction = 1;
	if (!this->getColor()) {
		row_direction = -1;
	}
	std::vector<Location> valid_moves = std::vector<Location>();
	//move up Straight
	if (gameBoard->getPiece(_location.row + row_direction, _location.column) == nullptr) {
		valid_moves.push_back(Location(_location.row + row_direction, _location.column));
	}
	//move up right
	Piece* p = gameBoard->getPiece(_location.row + row_direction, _location.column + 1);
	if (p != nullptr && p->getColor() != this->getColor()) {
		valid_moves.push_back(Location(_location.row + row_direction, _location.column + 1));
	}
	//move up left
	Piece* p = gameBoard->getPiece(_location.row + row_direction, _location.column - 1);
	if (p != nullptr && p->getColor() != this->getColor()) {
		valid_moves.push_back(Location(_location.row + row_direction, _location.column - 1));
	}

	//if not moved yet
	if (_not_moved) {
		Piece* p = gameBoard->getPiece(_location.row + (row_direction*2), _location.column);
		if (p == nullptr) {
			valid_moves.push_back(Location(_location.row + (row_direction * 2), _location.column);
		}
	}
}

