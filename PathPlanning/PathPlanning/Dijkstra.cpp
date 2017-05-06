#include "Dijkstra.h"
#include <cmath>
#include <queue>

using namespace std;

Dijkstra::Dijkstra()
{
	goalx = 0;
	goaly = 0;
}


Dijkstra::~Dijkstra()
{
}

Dijkstra::Dijkstra(float x, float y)
{
	goalx = x;
	goaly = y;
}

Path Dijkstra::calcPath(Grid g)
{
	vector<int> goalInt = g.intPos(goalx, goaly);
	if (goalInt[0] > g.map.size || goalInt[1] > g.map[0].size) {
		goal = g.R2Pos;
	}
	else{
		goal = g.map[goalInt[0]][goalInt[1]];
	}
	priority_queue <Coord, vector<Coord>, comp> queue;
	g.R2Pos.dist = 0;
	init = g.R2Pos;
	if (init.obst) {
		goal = init;
	}
	queue.push(g.R2Pos);
	Coord head;
	vector <Coord> neighbors;
	vector<int> intCoords;
	while (!(queue.top.equals(goal) || goal.equals(init))) {
		head = queue.top();
		queue.pop();
		intCoords = g.intPos(head.x, head.y);
		neighbors = g.adjCoords(intCoords[0], intCoords[1]);
		for (Coord c : neighbors) {
			if (c.dist == -1) {
				if (c.obst) {
					c.dist = numeric_limits<float>::infinity();
					if (c.equals(goal)) {
						goal = init;
					}
				}
				else {
					c.dist = g.distance(c, head) + head.dist;
				}
				queue.push(c);
			}
			else {
				c.dist = fmin(c.dist, c.dist + head.dist);
			}
		}
		head.track = true;
	}
	head = queue.top();
	return givePath(g);
}

Path Dijkstra::givePath(Grid g)
{
	Path moves;
	moves.path.push_back(goal);
	vector<int> intCoords = g.intPos(goal.x, goal.y);
	vector<Coord> neighbors = g.adjCoords(intCoords[0], intCoords[1]);
	Coord current = goal;
	current.track = false;
	while (!current.equals(init)) {
		for (Coord c : neighbors) {
			if (c.track && abs(c.dist - abs(current.dist - g.distance(c, current))) < .00001) {
				moves.path.push_back(c);
				c.track = false;
				current = c;
				break;
			}
		}
		intCoords = g.intPos(current.x, current.y);
		neighbors = g.adjCoords(intCoords[0], intCoords[1]);
		current.track = false;
	}
	return moves;
}

struct comp {
	bool operator()(Coord a, Coord b) {
		return a.dist < b.dist;
	}
};