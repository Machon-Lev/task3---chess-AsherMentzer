#include "Piece.h"


Piece::Piece(char PieceColor) : _pieceColor(PieceColor) {}

Piece::~Piece() {}

char Piece::GetColor() {return _pieceColor;}

bool Piece::IsLegalMove(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, Piece* GameBoard[8][8]) {
        Piece* qpDest = GameBoard[iDestRow][iDestCol];
        if ((qpDest == 0) || (_pieceColor != qpDest->GetColor())) {
            return AreSquaresLegal(iSrcRow, iSrcCol, iDestRow, iDestCol, GameBoard);
        }
        return false;
}
