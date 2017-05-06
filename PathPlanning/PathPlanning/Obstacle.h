#ifndef OBSTACLE_H
#define OBSTACLE_H
class Obstacle
{
public:
	Obstacle();
	~Obstacle();
	Obstacle(float x, float y, float h, float w);

	float xpos;
	float ypos;
	float height;
	float width;
};

#endif

