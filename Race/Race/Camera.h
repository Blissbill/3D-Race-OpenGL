#pragma once
#include "Common.h"
#include "GL/freeglut.h"

class Camera
{
public:
	Point position;
	Point direction;
	float angle;
	Camera()
	{
		position.x = 0;
		position.y = 0;
		position.z = 0;
		direction.x = 0;
		direction.y = 0;
		direction.z = -1;
		angle = 0;
	}

	void DrawCamera() const;
};
