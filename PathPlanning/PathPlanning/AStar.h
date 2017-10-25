#pragma once
#ifndef ASTAR_H
#define ASTAR_H

#include "Coord.h"
#include "Path.h"
#include "Grid.h"

class AStar
{
private:
	float goalx;
	float goaly;
	Coord goal;
	Coord init;

public:
	AStar();
	~AStar();

	Path calcPath(Grid *gri);

	Path givePath(Grid *grid);

};

#endif

