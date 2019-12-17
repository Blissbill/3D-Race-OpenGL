#pragma once
#include "Glm/glm.h"

class Road
{
	GLuint texture;
public:
	Road(GLuint texture)
	{
		this->texture = texture;
	}
	GLuint GetTexture() const;
};
