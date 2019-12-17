#include "Car.h"
GLMmodel* Car::GetModelCar() const
{
	return car;
}

GLMmodel* Car::GetModelTyre() const
{
	return tyre;
}
GLuint* Car::GetModelTextures() const
{
	return textures;
}

