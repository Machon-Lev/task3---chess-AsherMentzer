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
	/**
	 * @param The location row.
	 * @param The location column.
	 * @return The piece in this location, nullptr if no piece there.
	 */
	Piece* getPiece(int row, int col);
	/**
	 * @return True if is the white turn, false is the black turn.
	 */
	bool getPlayerColor();
	/**
	* @Brief Move the piece from source location to the destanation location
	 * @param The location source.
	 * @param The location destanation.
	 */
	void movePiece(Location src_location, Location _location);
	/**
	 * @Brief Undo move of the piece from source location to the destanation location.
	 * @param The location source.
	 * @param The location destanation.
	 * @param The piece to move.
	 */
	void undoMove(Location src_location, Location dst_location,Piece* piece);
	/**
	* @param The player to check true=white ,false=black.
	 * @return True if there is chekc on this player, false is not.
	 */
	bool isInCheck(bool player);
	/**
	* @param The player to check true=white ,false=black.
	 * @return True if there is chekc mate on this player, false is not.
	 */
	bool isCheckMate(bool player);
	/**
	* @Brief Do command of Move the piece from source location to the destanation location
	 * @param The location source.
	 * @param The location destanation.
	 * @return The code response to this command.
	 */
	int do_command(Location src_location, Location dst_location);
private:
	Piece* _gameBoard[ROW_SIZE][COL_SIZE];
	Piece* _white_king;
	Piece* _black_king;
	bool _white_turn;
	bool _check_mate;
	Location getKingLocation(bool player);
	void initRegularBoard();
};

