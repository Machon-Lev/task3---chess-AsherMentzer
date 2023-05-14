#pragma once
#include "Piece.h"
class Rook:public Piece
{
public:
	Rook(char cColor);
	~Rook();

private:
    virtual char GetPiece();
	bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, Piece* GameBoard[8][8]);
};

