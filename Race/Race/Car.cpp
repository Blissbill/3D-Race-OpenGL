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
void Car::DrawCar() const
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(position.x, 0.6, position.z);
	glBindTexture(GL_TEXTURE_2D, GetModelTextures()[enums::Car]);
	glmDraw(GetModelCar(), GLM_SMOOTH | GLM_TEXTURE);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}


