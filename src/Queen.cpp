#include "..\include\queen.h"

Queen::Queen(bool player, Location location) :Piece(player, location){}

Queen::~Queen(){}

bool Queen::isValidMove(Location dst_location, Board* gameBoard)
{
	std::vector<Location> valid_moves = getAllValidMoves(gameBoard);
	if (std::find(valid_moves.begin(), valid_moves.end(), dst_location) == valid_moves.end())
		return false;
	return true;
}

std::vector<Location> Queen::getAllValidMoves(Board* gameBoard)
{
	std::vector<Location> valid_moves = std::vector<Location>();
	//move in the rows form current location to -> 8
	for (int i = _location.row + 1; i < ROW_SIZE; ++i) {
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
	for (int i = _location.column + 1; i < COL_SIZE; ++i) {
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
	//move diagonal up right
	for (int i = _location.row + 1, j = _location.column + 1; i < ROW_SIZE && j < COL_SIZE; ++i, ++j) {
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
	for (int i = _location.row + 1, j = _location.column - 1; i < ROW_SIZE && j < COL_SIZE; ++i, --j) {
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


