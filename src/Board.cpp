#include "Board.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"



const int white_pawn_row = 1;
const int black_pawn_row = 6;


Board::Board()
{
	initRegularBoard();
	_black_king = _gameBoard[7][4];
	_white_king = _gameBoard[0][4];
	_check_mate = false;
}

Board::Board(std::string pieces)
{
	initRegularBoard();
	_black_king = _gameBoard[7][4];
	_white_king = _gameBoard[0][4];
	_check_mate = false;
}

Board::~Board() {
	for (int i = 0; i < ROW_SIZE; i++)
	{
		for (int j = 0; j < COL_SIZE; j++)
		{
			if (_gameBoard[i][j] != nullptr)
			{
				delete _gameBoard[i][j];
				_gameBoard[i][j] = nullptr;
			}
		}
	}
	_white_king = nullptr;
	_black_king = nullptr;
}
Piece* Board::getPiece(int row, int col)
{
	return nullptr;
}
bool Board::getPlayerColor()
{
	return false;
}
void Board::initRegularBoard() {

	for (int i = 0; i < ROW_SIZE; i++)
		for (int j = 0; j < COL_SIZE; j++)
			_gameBoard[i][j] = nullptr;

	_white_turn = true;
	_gameBoard[0][0] = new Rook(true, Location(0, 0));
	_gameBoard[0][7] = new Rook(true, Location(0, 7));
	_gameBoard[7][0] = new Rook(false, Location(7, 0));
	_gameBoard[7][7] = new Rook(false, Location(7, 7));
	_gameBoard[0][4] = new King(true, Location(0, 4));
	_gameBoard[7][4] = new King(false, Location(7, 4));
	_gameBoard[0][2] = new Bishop(true, Location(0, 2));
	_gameBoard[0][5] = new Bishop(true, Location(0, 5));
	_gameBoard[7][2] = new Bishop(false, Location(7, 2));
	_gameBoard[7][5] = new Bishop(false, Location(7, 5));
	_gameBoard[0][3] = new Queen(true, Location(0, 3));
	_gameBoard[7][3] = new Queen(false, Location(7, 3));
	_gameBoard[0][1] = new Knight(true, Location(0, 1));
	_gameBoard[0][6] = new Knight(true, Location(0, 6));
	_gameBoard[7][1] = new Knight(false, Location(7, 1));
	_gameBoard[7][6] = new Knight(false, Location(7, 6));
	for (int column = 0; column < COL_SIZE; column++)
	{
		_gameBoard[white_pawn_row][column] = new Pawn(true, Location(white_pawn_row, column));
		_gameBoard[black_pawn_row][column] = new Pawn(false, Location(black_pawn_row, column));
	}

}
Location Board::getKingLocation(bool player) {
	return (player) ? _white_king->getLocation() : _black_king->getLocation();
}

int Board::do_move(Location src_location,Location dst_location) {


	Piece* source = _gameBoard[src_location.row][src_location.column];
	Piece* target = _gameBoard[dst_location.row][dst_location.column];

	if (source == nullptr)
		return 11;
	if (source->getColor() != _white_turn)
		return 12;
	if (target != nullptr && target->getColor() == _white_turn)
		return 13;
	if (_check_mate == _white_turn)
		return 31;
	if (!source->isValidMove(dst_location, this))
		return 21;
	if (isInCheck(_white_turn) && isCheckMate(_white_turn))
	{
		_check_mate = _white_turn;
		return 31;
	}
	movePiece(src_location,dst_location);


	if (isInCheck(_white_turn))
	{
		undoMove(src_location,dst_location, target);
		return 21;
	}

	int result;
	if (isInCheck(!(_white_turn)))
		result = 41;
	else
		result = 42;

	if (target != nullptr)
		delete target;
	target = nullptr;
	source = nullptr;
	_white_turn = !_white_turn;
	return result;
}

void Board::movePiece(Location src_location, Location dst_location) {

	_gameBoard[dst_location.row][dst_location.column] = 
		_gameBoard[src_location.row][src_location.column];
	_gameBoard[dst_location.row][dst_location.column]->setLocation(dst_location);

	_gameBoard[src_location.row][src_location.column] = nullptr;
}
void Board::undoMove(Location src_location, Location dst_location, Piece* target)
{
	_gameBoard[src_location.row][src_location.column] = 
		_gameBoard[dst_location.row][dst_location.column];
	_gameBoard[src_location.row][src_location.column]->setLocation(src_location);
	_gameBoard[dst_location.row][dst_location.column] = target;
	target = nullptr;
}

bool Board::isInCheck(bool player) {
	Location king_location = getKingLocation(player);
	for (int i = 0; i < ROW_SIZE; i++)
	{
		for (int j = 0; j < COL_SIZE; j++)
		{
			Piece* p = _gameBoard[i][j];
			if (p != nullptr && p->getColor() != player)
			{
				auto p_moves = p->getAllValidMoves(this);
				if (std::find(p_moves.begin(), p_moves.end(), king_location) != p_moves.end())
					return true;

			}
		}
	}
	return false;
}
bool Board::isCheckMate(bool player) {
	int target_row, target_col;
	Piece* target;
	for (int i = 0; i < ROW_SIZE; i++)
	{
		for (int j = 0; j < COL_SIZE; j++)
		{
			Piece* source = _gameBoard[i][j];
			if (source != nullptr && source->getColor() == player)
			{
				auto p_moves = source->getAllValidMoves(this);
				for (auto move : p_moves)
				{
					target = _gameBoard[move.row][move.column];
					movePiece(Location(i, j), move);
					if (!isInCheck(player))
					{
						undoMove(Location(i, j),move, target);
						return false;
					}
					undoMove(Location(i, j), move, target);
					target = nullptr;
				}
			}
			source = nullptr;
		}
	}
	return true;
}