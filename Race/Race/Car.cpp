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
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex3d(-10 + position.x, position.y, position.z);
	glVertex3d(10 + position.x, position.y, position.z);

	glVertex3d(position.x, -10 + position.y, position.z);
	glVertex3d(position.x, 10 + position.y, position.z);

	glVertex3d(position.x, position.y, -10 + position.z);
	glVertex3d(position.x, position.y, 10 + position.z);

	glEnd();
}


