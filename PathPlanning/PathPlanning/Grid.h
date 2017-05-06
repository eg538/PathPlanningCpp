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
	Grid(float w, float h, float scal, float startx, float starty);

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

	vector<int> intPos(float x, float y);
};

#endif
