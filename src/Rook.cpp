#include "Rook.h"

Rook::Rook(bool player, Location location):Piece(player,location){}

Rook::~Rook()
{
}

bool Rook::isValidMove(Location dst_location, Board* gameBoard)
{
	//if is not move in the same row or the same column
	if (_location.row != dst_location.row && _location.column != dst_location.column)
		return false;
	std::vector<Location> valid_moves = getAllValidMoves(gameBoard);
	if (std::find(valid_moves.begin(), valid_moves.end(), dst_location) == valid_moves.end())
		return false;
	return true;
}

std::vector<Location> Rook::getAllValidMoves(Board* gameBoard)
{
	std::vector<Location> valid_moves = std::vector<Location>();
	//move in the rows form current location to -> 8
	for (int i = _location.row+1; i < ROW_SIZE; ++i) {
		Piece* p = gameBoard->getPiece(i, _location.column);
		//empty spot
		if (p == nullptr) {
			valid_moves.push_back(Location(i, _location.column));
		}
		// if is same player piece
		else if (getColor() == p->getColor()) {
			break;
		}
		//other player piece
		else {
			valid_moves.push_back(Location(i, _location.column));
			break;
		}

	}
	//move in the rows form 0 to current location
	for (int i = 0; i < _location.row; ++i) {
		Piece* p = gameBoard->getPiece(i, _location.column);
		//empty spot
		if (p == nullptr) {
			valid_moves.push_back(Location(i, _location.column));
		}
		// if is same player piece
		else if (getColor() == p->getColor()) {
			break;
		}
		//other player piece
		else {
			valid_moves.push_back(Location(i, _location.column));
			break;
		}

	}
	//move in the column form current location to -> 8
	for (int i = _location.column +1 ; i < COL_SIZE; ++i) {
		Piece* p = gameBoard->getPiece(_location.row,i);
		//empty spot
		if (p == nullptr) {
			valid_moves.push_back(Location(_location.row, i));
		}
		// if is same player piece
		else if (getColor() == p->getColor()) {
			break;
		}
		//other player piece
		else {
			valid_moves.push_back(Location(_location.row, i));
			break;
		}
	}
	//move in the column form 0 to current location
	for (int i = 0; i < _location.column; ++i) {
		Piece* p = gameBoard->getPiece(_location.row, i);
		//empty spot
		if (p == nullptr) {
			valid_moves.push_back(Location(_location.row, i));
		}
		// if is same player piece
		else if (getColor() == p->getColor()) {
			break;
		}
		//other player piece
		else {
			valid_moves.push_back(Location(_location.row, i));
			break;
		}

	}
	return valid_moves;
}

