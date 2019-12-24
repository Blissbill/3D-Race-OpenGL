#pragma once
#include "Glm/glm.h"
#include "Common.h"

class Car
{
	GLuint carTexture;
	GLuint tyreTexture;
	GLMmodel* car;
	GLMmodel* tyre;
public:
	Point position;
	float speed;
	float rot;
	Car(GLuint carTexture, GLuint tyreTexture, GLMmodel* carModel, GLMmodel* tyreModel)
	{
		position.x = 0;
		position.y = 0;
		position.z = 0;
		speed = 100;
		this->carTexture = carTexture;
		this->tyreTexture = tyreTexture;
		car = carModel;
		tyre = tyreModel;
		rot = 0;
	}

	GLMmodel* GetModelCar() const;
	GLMmodel* GetModelTyre() const;
	GLuint* GetModelTextures() const;
	void DrawCar() const;
};
