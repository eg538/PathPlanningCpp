#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Coord.h"
#include "Path.h"
#include "Grid.h"

class Dijkstra
{
private:
	float goalx;
	float goaly;
	Coord goal;
	Coord init;

public:
	Dijkstra();
	~Dijkstra();

	Path calcPath(Grid g);

	Path givePath(Grid g);
};

#endif

