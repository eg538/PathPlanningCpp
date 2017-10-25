#include "Obstacle.h"



Obstacle::Obstacle()
{
}


Obstacle::~Obstacle()
{
}

Obstacle::Obstacle(float x, float y, float h, float w)
{
	top = y - h * .5f - 13.f;
	bottom = y + h * .5f + 13.f;
	left = x - w * .5f - 13.f;
	right = x + w * .5f + 13.f;
}
