#include "Car.h"


GLMmodel* Car::GetModelCar() const
{
	return car;
}

GLMmodel* Car::GetModelTyre() const
{
	return tyre;
}
GLuint Car::GetModelTextures() const
{
	return carTexture;
}
GLuint Car::GetTyreTextures() const
{
	return tyreTexture;
}
void Car::DrawCar() const
{
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, GetModelTextures());
	glPushMatrix();
	glTranslatef(position.x, 0.6, position.z);
	glRotatef(rot, 0, 1, 0);
	glmDraw(GetModelCar(), GLM_SMOOTH | GLM_TEXTURE);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, GetTyreTextures());
	
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	if (rot > 0)
	{
		glTranslatef(position.x - 1.2, 0.3, position.z - 0.8);
		glRotatef(rot + 20, 0, 1, 0);
	}
	else
		glTranslatef(position.x - 0.8, 0.3, position.z - 1.2);
	
	glRotatef(rotTyre, -1, 0, 0);
	glmDraw(GetModelTyre(), GLM_SMOOTH | GLM_TEXTURE);
	glPopMatrix();
	
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	if(rot != 0)
		glTranslatef(position.x - 0.4, 0.3, position.z + 1.40);
	else
		glTranslatef(position.x - 0.85, 0.3, position.z + 1.2);
	glRotatef(rot, 0, 1, 0);
	glRotatef(rotTyre, -1, 0, 0);
	glmDraw(GetModelTyre(), GLM_SMOOTH | GLM_TEXTURE);
	glPopMatrix();
	
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	if (rot < 0)
	{
		glTranslatef(position.x + 1.2, 0.3, position.z - 0.8);
		glRotatef(rot - 20, 0, 1, 0);
	}
	else
		glTranslatef(position.x + 0.8, 0.3, position.z - 1.2);
	glRotatef(180, 0, 1, 0);
	glRotatef(rotTyre, 1, 0, 0);
	glmDraw(GetModelTyre(), GLM_SMOOTH | GLM_TEXTURE);
	glPopMatrix();

	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	if (rot != 0)
		glTranslatef(position.x + 0.4, 0.3, position.z + 1.40);
	else
		glTranslatef(position.x + 0.85, 0.3, position.z + 1.2);
	glRotatef(rot, 0, 1, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(rotTyre, 1, 0, 0);
	glmDraw(GetModelTyre(), GLM_SMOOTH | GLM_TEXTURE);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}


