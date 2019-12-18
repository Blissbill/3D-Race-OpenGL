#pragma once
#include "Glm/glm.h"
#include "Common.h"

class Car
{
	GLuint * textures;
	GLMmodel* car;
	GLMmodel* tyre;
public:
	Point position;
	float speed;
	Car(GLuint *textures, GLMmodel** models)
	{
		position.x = 0;
		position.y = 0;
		position.z = 0;
		speed = 100;
		this->textures = textures;
		car = models[enums::Car];
		tyre = models[enums::Tyre];
	}

	GLMmodel* GetModelCar() const;
	GLMmodel* GetModelTyre() const;
	GLuint* GetModelTextures() const;
	void DrawCar() const;
};
