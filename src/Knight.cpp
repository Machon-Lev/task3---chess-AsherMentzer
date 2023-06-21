#include "..\include\Knight.h"

Knight::Knight(bool player, Location location) :Piece(player, location){}

Knight::~Knight(){}

bool Knight::isValidMove(Location dst_location, Board* gameBoard)
{
	std::vector<Location> valid_moves = getAllValidMoves(gameBoard);
	if (std::find(valid_moves.begin(), valid_moves.end(), dst_location) == valid_moves.end())
		return false;
	return true;
}

std::vector<Location> Knight::getAllValidMoves(Board* gameBoard)
{
	std::vector<Location> valid_moves = std::vector<Location>();
	//([-2,-1],[-2,+1],[-1,-2],[-1,+2],[+1,-2],[+1,+2],[+2,-1],[+2,+1])
	std::vector<Location> possible_locations = { Location(_location.row - 2,_location.column - 1)
		,Location(_location.row - 2,_location.column+1)
	,Location(_location.row - 1,_location.column -2)
		,Location(_location.row - 1,_location.column + 2)
			,Location(_location.row + 1,_location.column - 2)
				,Location(_location.row + 1,_location.column+2)
					,Location(_location.row+2,_location.column - 1)
	,Location(_location.row+2,_location.column + 1) };
	for (auto loc : possible_locations) {
		if (loc.row >= 0 && loc.row < ROW_SIZE && loc.column >= 0 && loc.column < COL_SIZE) {
			Piece* p = gameBoard->getPiece(loc.row, loc.column);
			if (p == nullptr || p->getColor() != this->getColor()) {
				valid_moves.push_back(loc);
			}
		}
	}
	return valid_moves;
}
