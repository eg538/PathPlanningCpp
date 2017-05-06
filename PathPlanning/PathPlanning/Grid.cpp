#include "Grid.h"
#include <cmath>

Grid::Grid()
{
}


Grid::~Grid()
{
}

Grid::Grid(float w, float h, float scal, float startx, float starty)
{
	width = w;
	height = h;
	scale = scal;
	nheight = (int)(h / scal + .5);
	nwidth = (int)(w / scal + .5);
	vector<vector <Coord>> map;
	Coord R2Pos(startx, starty);
	vector <Obstacle> obstacles;
	vector<int> intInit = intPos(startx, starty);
	for (int i = 0; i < nheight; i++) {
		for (int j = 0; j < nwidth; j++) {
			map[i][j] = Coord((.5f) * scale + scale * ((float)(j)), (.5f) * scale + scale * ((float)(i)));
		}
	}
	map[intInit[0]][intInit[1]] = R2Pos;
}

void Grid::addObstacles(Obstacle obst)
{
	obstacles.push_back(obst);
	float top;
	float bottom;
	float left;
	float right;
	vector<int> coordsOne;
	vector<int> coordsTwo;
	top = obst.ypos - obst.height * .5f - 13.f;
	if (top < 0) {
		top = 0;
	}
	bottom = obst.ypos + obst.height * .5f + 13.f;
	if (bottom > height) {
		bottom = height;
	}
	left = obst.xpos - obst.width * .5f - 13.f;
	if (left < 0) {
		left = 0;
	}
	right = obst.xpos + obst.width * .5f + 13.f;
	if (right > width) {
		right = width;
	}
	coordsOne = intPos(left, top);
	coordsTwo = intPos(right, bottom);
	for (int t = coordsOne[0]; t <= coordsTwo[0]; t++) {
		for (int u = coordsOne[1]; u <= coordsTwo[1]; u++) {
			map[t][u].obst = true;

		}
	}
}

std::vector<Coord> Grid::adjCoords(int x, int y)
{
	vector<Coord> adj;
	if (x + 1 < nheight) {
		adj.push_back(map[x + 1][y]);
		if (y + 1 < nwidth) {
			adj.push_back(map[x + 1][y + 1]);
		}
	}
	if (y + 1 < nwidth) {
		adj.push_back(map[x][y + 1]);
	}
	if (x - 1 >= 0) {
		adj.push_back(map[x - 1][y]);
		if (y + 1 < nwidth) {
			adj.push_back(map[x - 1][y + 1]);
		}
		if (y - 1 >= 0) {
			adj.push_back(map[x - 1][y - 1]);
		}
	}
	if (y - 1 >= 0) {
		adj.push_back(map[x][y - 1]);
		if (x + 1 < nheight) {
			adj.push_back(map[x + 1][y - 1]);
		}
	}
	return adj;
}

std::vector<int> Grid::intPos(float x, float y)
{
	vector<int> pos;
	pos[0] = (int)((y - (.5f) * scale) / scale + .5);
	pos[1] = (int)((x - (.5f) * scale) / scale + .5);
	return pos;
	return pos;
}

float Grid::distance(Coord a, Coord b)
{
	return (float)sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

void Grid::updatePos(float x, float y)
{
	R2Pos = Coord(x, y);
}

