#include "..\include\Bishop.h"

Bishop::Bishop(bool player, Location location) :Piece(player, location){}

Bishop::~Bishop(){}

bool Bishop::isValidMove(Location dst_location, Board* gameBoard)
{
	//if is  move in the same row or the same column
	if (_location.row = dst_location.row || _location.column == dst_location.column)
		return false;
	std::vector<Location> valid_moves = getAllValidMoves(gameBoard);
	if (std::find(valid_moves.begin(), valid_moves.end(), dst_location) == valid_moves.end())
		return false;
	return true;
}

std::vector<Location> Bishop::getAllValidMoves(Board* gameBoard)
{
	std::vector<Location> valid_moves = std::vector<Location>();
	//move diagonal up right
	for (int i = _location.row + 1,j= _location.column + 1; i < ROW_SIZE && j < COL_SIZE; ++i, ++j) {
		Piece* p = gameBoard->getPiece(i, j);
		//empty spot
		if (p == nullptr) {
			valid_moves.push_back(Location(i, j));
		}
		// if is same player piece
		else if (getColor() == p->getColor()) {
			break;
		}
		//other player piece
		else {
			valid_moves.push_back(Location(i, j));
			break;
		}

	}
	//move diagonal up left
	for (int i = _location.row + 1, j = _location.column -1; i < ROW_SIZE && j < COL_SIZE; ++i, --j) {
		Piece* p = gameBoard->getPiece(i, j);
		//empty spot
		if (p == nullptr) {
			valid_moves.push_back(Location(i, j));
		}
		// if is same player piece
		else if (getColor() == p->getColor()) {
			break;
		}
		//other player piece
		else {
			valid_moves.push_back(Location(i, j));
			break;
		}

	}
	//move diagonal down right
	for (int i = _location.row - 1, j = _location.column + 1; i < ROW_SIZE && j < COL_SIZE; --i, ++j) {
		Piece* p = gameBoard->getPiece(i, j);
		//empty spot
		if (p == nullptr) {
			valid_moves.push_back(Location(i, j));
		}
		// if is same player piece
		else if (getColor() == p->getColor()) {
			break;
		}
		//other player piece
		else {
			valid_moves.push_back(Location(i, j));
			break;
		}

	}
	//move diagonal down left
	for (int i = _location.row - 1, j = _location.column - 1; i < ROW_SIZE && j < COL_SIZE; --i, --j) {
		Piece* p = gameBoard->getPiece(i, j);
		//empty spot
		if (p == nullptr) {
			valid_moves.push_back(Location(i, j));
		}
		// if is same player piece
		else if (getColor() == p->getColor()) {
			break;
		}
		//other player piece
		else {
			valid_moves.push_back(Location(i, j));
			break;
		}

	}
	return valid_moves;
}

