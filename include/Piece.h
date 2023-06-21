#pragma once
#include "Board.h"
#include "Location.h"
#include <vector>
class Board;

/*
* @class Piece
* @Brief represent a piece on the game board
*/
class Piece
{
protected:
    bool _white;// whitch player theis piece is
    Location _location;// location of the piece on the game board
public:
    Piece(bool white, Location location);
    virtual ~Piece();
    /**
     * @brief Checks if the piece can move to the specified destination location.
     *
     * @param dest The destination location to check.
     * @param gameBoard Pointer to the current game state.
     * @return True if the move is valid, false otherwise.
     */
    virtual bool isValidMove(Location dest_location, Board* gameBoard) = 0;
    /**
     * @brief Collect all the locationn this piece can move to.
     *
     * @param gameState Pointer to the current game state.
     * @return vector of all the locations.
     */
    virtual std::vector<Location>getAllValidMoves(Board* gameBoard) = 0;
    /**
     * @return True if is white piece, false if is black piece.
     */
    bool getColor();
    /**
     * @return The location of this piece.
     */
    Location getLocation();
    /**
    * 
     * @Brief Set the location of this piece.
     */
    void setLocation(Location new_location);
};
