#include "Grid.h"
#include "Dijkstra.h"
#include "PathPlanningHandler.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	int goalx = 999;
	int goaly = -1;
	PathPlanningHandler testing(goalx, goaly);
	vector<Obstacle> obst{};
	float centerx;
	float centery;
	float height;
	float width;
	int maxCoord = 550;
	int minCoord = 15;
	int maxSize = 100;
	int minSize = 30;
	int obsAdd = 1;
	while (!testing.targetReached) {
		obsAdd = 0 + (rand() % static_cast<int>(2 - 0 + 2));
		cout << "Add obstacle: " << obsAdd << endl;
		if (obsAdd == 1) {
			centerx = minCoord + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (maxCoord - minCoord)));
			centery = minCoord + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (maxCoord - minCoord)));
			height = minSize + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (maxSize - minSize)));
			width = minSize + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (maxSize - minSize)));
			Obstacle x(centerx, centery, height, width);
			obst.push_back(x);
		}
		else {
			obst.clear();
		}
		testing.execute(obst);
	}
	

	system("PAUSE");
}