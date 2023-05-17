#pragma once
#include "Board.h"
#include "Location.h"
#include <vector>
class Board;

class Piece
{
protected:
    bool _white;
    Location _location;
public:
    Piece(bool white, Location location);
    ~Piece();
    virtual bool isValidMove(Location dest_location, Board* gameBoard) = 0;
    virtual std::vector<Location>getAllValidMoves(Board* gameBoard) = 0;
    bool getColor();
    Location getLocation();
    void setLocation(Location new_location);
};
