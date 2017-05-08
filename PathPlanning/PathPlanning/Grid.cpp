#include "Grid.h"
#include <cmath>
#include <iostream>

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
	map = vector<vector <Coord>>(nheight, vector<Coord>(nwidth));
	R2Pos = Coord (startx, starty);
	obstacles = vector <Obstacle>();
	vector<int> intInit = intPos(startx, starty);
	for (int i = 0; i < nheight; i++) {
		for (int j = 0; j < nwidth; j++) {
			map[i][j] = Coord((.5f) * scale + scale * ((float)(j)), (.5f) * scale + scale * ((float)(i)));
		}
	}
	map[intInit[0]][intInit[1]] = R2Pos;
}

void Grid::addObstacle(Obstacle obst)
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

std::vector<vector<int>> Grid::adjCoords(int x, int y)
{
	vector<vector <int>> adj(0, vector<int>(2));
	vector<int> coords;
	
	if (x + 1 < nheight) {
		coords.push_back(x + 1);
		coords.push_back(y);
		adj.push_back(coords);
		coords.clear();
		if (y + 1 < nwidth) {
			coords.push_back(x + 1);
			coords.push_back(y + 1);
			adj.push_back(coords);
			coords.clear();
		}
	}
	if (y + 1 < nwidth) {
		coords.push_back(x);
		coords.push_back(y + 1);
		adj.push_back(coords);
		coords.clear();
	}
	if (x - 1 >= 0) {
		coords.push_back(x - 1);
		coords.push_back(y);
		adj.push_back(coords);
		coords.clear();
		if (y + 1 < nwidth) {
			coords.push_back(x - 1);
			coords.push_back(y + 1);
			adj.push_back(coords);
			coords.clear();
		}
		if (y - 1 >= 0) {
			coords.push_back(x - 1);
			coords.push_back(y - 1);
			adj.push_back(coords);
			coords.clear();
		}
	}
	if (y - 1 >= 0) {
		coords.push_back(x);
		coords.push_back(y - 1);
		adj.push_back(coords);
		coords.clear();
		if (x + 1 < nheight) {
			coords.push_back(x + 1);
			coords.push_back(y - 1);
			adj.push_back(coords);
			coords.clear();
		}
	}
	return adj;
}

std::vector<int> Grid::intPos(float x, float y)
{
	vector<int> pos;
	pos.push_back((int)((y - (.5f) * scale) / scale + .5));
	pos.push_back((int)((x - (.5f) * scale) / scale + .5));
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

