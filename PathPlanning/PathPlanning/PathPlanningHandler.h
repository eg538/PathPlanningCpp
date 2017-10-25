#pragma once
#ifndef PPH_H
#define PPH_H
#include "Grid.h"
#include "Dijkstra.h"
#include "Path.h"
#include "Obstacle.h"

class PathPlanningHandler
{
private:
	Grid g;
	Dijkstra shortPath;
	Path path;
	int track;
	int goalx;
	int goaly; 
public:
	PathPlanningHandler(int glx, int gly);
	PathPlanningHandler();
	~PathPlanningHandler();
	bool targetReached;

	string printMap();
	void print();

	void execute(vector<Obstacle> obs);

};

#endif