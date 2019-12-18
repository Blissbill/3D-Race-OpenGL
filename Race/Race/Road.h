#pragma once
#include "Glm/glm.h"
#include "Common.h"

class Road
{
	GLuint texture;
public:
	Point position;
	float width;
	Road(GLuint texture)
	{
		position.x = 0;
		position.y = 0;
		position.z = 100;
		width = 7;
		this->texture = texture;
	}
	GLuint GetTexture() const;
	void DrawRoad(float) const;
	
};
