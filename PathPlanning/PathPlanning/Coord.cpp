#include "Coord.h"



Coord::Coord()
{
	x = 0;
	y = 0;
	obst = false;
	dist = -1;
	track = false;
}


Coord::~Coord()
{
}

Coord::Coord(float xcoords, float ycoords)
{
	x = xcoords;
	y = ycoords;
	obst = false;
	dist = -1;
	track = false;
}

void Coord::setObst(bool val)
{
	obst = val;
}

bool Coord::equals(Coord compare)
{
	return x == compare.x && y == compare.y;
}
