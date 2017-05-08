#include "Grid.h"
#include "Dijkstra.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	Grid grid(100.f, 100.f, 1.f, 20.f, 20.f);
	Grid *g = &grid;
	Coord position = grid.R2Pos;
	Dijkstra d(80.f, 50.f);
	Obstacle testing(60.f, 60.f, 20.7f, 10.89f);
	grid.addObstacle(testing);
	Path p = d.calcPath(g);

	for (Coord c: p.path) {
		string s = c.toString();
		cout << s << endl;
	}
	
	system("PAUSE");
}