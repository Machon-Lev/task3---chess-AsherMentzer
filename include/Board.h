#pragma once
#include "Piece.h"
#include "string.h"
#include "Location.h"
#include <string>

const int ROW_SIZE = 8;
const int COL_SIZE = 8;

class Piece;

class Board
{
public:
	Board();
	Board(std::string pieces);
	~Board();
	Piece* getPiece(int row, int col);
	bool getPlayerColor();
	void movePiece(Location src_location, Location _location);
	void undoMove(Location src_location, Location dst_location,Piece* piece);
	bool isInCheck(bool player);
	bool isCheckMate(bool player);
	int do_move(Location src_location, Location dst_location);
	//Piece** getGameBoarg();
private:
	Piece* _gameBoard[ROW_SIZE][COL_SIZE];
	Piece* _white_king;
	Piece* _black_king;
	bool _white_turn;
	bool _check_mate;
	Location getKingLocation(bool player);
	void initRegularBoard();
};

