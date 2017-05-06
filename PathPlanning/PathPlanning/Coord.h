#ifndef COORD_H
#define COORD_H

#include <string>

class Coord
{
public:
	Coord();
	~Coord();
	Coord(float xcoords, float ycoords);

	float x;
	float y;
	bool obst;
	float dist;
	bool track;

	void setObst(bool val);

	bool equals(Coord compare);
	
};

#endif