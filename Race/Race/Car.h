#pragma once
#include "Glm/glm.h"
#include "Enums.h"

struct Point
{
	float x;
	float y;
};

class Car
{
	GLuint * textures;
	GLMmodel* car;
	GLMmodel* tyre;
public:
	Point Position;
	Car(GLuint *textures, GLMmodel** models)
	{
		Position.x = 0;
		Position.y = 0;
		this->textures = textures;
		car = models[enums::Car];
		tyre = models[enums::Tyre];
	}

	GLMmodel* GetModelCar() const;
	GLMmodel* GetModelTyre() const;
	GLuint* GetModelTextures() const;
};