#ifndef OBSTACLE_H
#define OBSTACLE_H
class Obstacle
{
public:
	Obstacle();
	~Obstacle();
	Obstacle(float x, float y, float h, float w);

	float top;
	float bottom;
	float left;
	float right;
};

#endif

