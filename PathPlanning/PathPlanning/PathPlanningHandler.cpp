#include "PathPlanningHandler.h"
#include <iostream>
#include <iomanip>

using namespace std;

PathPlanningHandler::PathPlanningHandler(int glx, int gly)
{
	g = Grid(1000, 1000, 25, 10, 26);
	shortPath = Dijkstra(&g);
	goalx = glx;
	goaly = gly;
	path = shortPath.calcPath(goalx, goaly);
	print();
	track = 1;
	targetReached = false;
}

PathPlanningHandler::PathPlanningHandler() {

}

PathPlanningHandler::~PathPlanningHandler()
{
}

void PathPlanningHandler::execute(vector<Obstacle> obs)
{
	if (!obs.empty()) {
		for (int i = 0; i < obs.size(); i++) {
			g.addObstacle(obs[i]);
		}
		path = shortPath.calcPath(goalx, goaly);
		track = 1;
	}
	else if (!path.path.empty()) {
		//Extract next coordinate from shortest path and calculate motor commands
		Coord moveTo = path.path.back();
		path.path.pop_back();
		track++;
		g.updatePos(moveTo.row, moveTo.column);
		print();
	}
	else {
		//Stop motors if no path or goal reached
		targetReached = true;
		cout << "Done" << endl;
	}
}

string PathPlanningHandler::printMap() {
	string map;
	for (int i = 0; i < g.map.size(); i++) {
		for (int j = 0; j < g.map[i].size(); j++) {
			if (g.map[i][j]->obst) {
				map.append("H ");
			}
			else if (find(path.path.begin(), path.path.end(), *(g.map[i][j])) != path.path.end()) {
				map.append("* ");
			}
			else {
				map.append("O ");
			}
		}
		map.append("\n");
	}
	map.append("----------- \n");
}

void PathPlanningHandler::print()
{
	cout << "  ";
	for (int j = 0; j < g.map[0].size(); j++) {
		cout << setfill(' ') << setw(2) << internal;
		cout << j % 10;
	}
	cout << endl;
	for (int i = 0; i < g.map.size(); i++) {
		cout << setfill(' ') << setw(2) << internal;
		cout << i % 10 << " ";
		for (int j = 0; j < g.map[i].size(); j++) {
			cout << setfill(' ') << setw(2) << internal;
			if (g.map[i][j]->obst) {
				cout << "H ";
			}
			else if (find(path.path.begin(), path.path.end(), *(g.map[i][j])) != path.path.end()) {
				cout << "* ";
			}
			else {
				cout << "O ";
			}
		}
		cout << endl;
	}
	cout << "-----------" << endl;
}
