#ifndef GRID_H
#define GRID_H

#include "Coord.h"
#include "Obstacle.h"

#include <vector>

using namespace std;

class Grid
{
public:
	Grid();
	~Grid();

	int nheight;
	float height;
	int nwidth;
	float width;
	float scale;
	Coord R2Pos;
	Coord* map;
	vector<Obstacle> obstacles;

	void addObstacles(Obstacle obst);

	vector<Coord> adjCoords(int x, int y);

	array<int, 2> intPos(float x, float y);
};

#endif
