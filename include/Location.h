#pragma once
/*
* @brief represent location on the chess board
*/
struct Location {
	int row;
	int column;
};

// operators on Location.
Location operator+(const Location& loc1, const Location& loc2);
Location& operator+=(Location& loc1, const Location& loc2);
bool operator==(const Location& loc1, const Location& loc2);
bool operator!=(const Location& loc1, const Location& loc2);
Location operator-(const Location& loc1, const Location& loc2);
Location operator/(const Location& loc1, const Location& loc2);
Location operator*(const Location& loc1, int multiplier);
