#include "Location.h"
#include <cstdlib>
#include <ostream>

std::ostream& operator<<(std::ostream& os, const Location& loc)
{
	os << "row: " << loc.row << " column: " << loc.column << "\n";
	return os;
}

Location operator+(const Location& loc1, const Location& loc2)
{
	return Location{ loc1.row + loc2.row, loc1.column + loc2.column };
}

Location operator-(const Location& loc1, const Location& loc2)
{
	return Location{ loc1.row + -1 * loc2.row, loc1.column + -1 * loc2.column };
}

// Simplifying(reducing) the location.
Location operator/(const Location& loc1, const Location& loc2)
{
	int row = loc2.row != 0 ? loc1.row / abs(loc2.row) : loc1.row;
	int col = loc2.column != 0 ? loc1.column / abs(loc2.column) : loc1.column;
	return Location{ row, col };
}

Location operator*(const Location& loc1, int multiplier)
{
	return Location{ loc1.row * multiplier, loc1.column * multiplier };
}

Location& operator+=(Location& loc1, const Location& loc2)
{
	loc1.row += loc2.row;
	loc1.column += loc2.column;
	return loc1;
}

bool operator==(const Location& loc1, const Location& loc2)
{
	return loc1.row == loc2.row && loc1.column == loc2.column;
}

bool operator!=(const Location& loc1, const Location& loc2)
{
	return !(loc1 == loc2);
}