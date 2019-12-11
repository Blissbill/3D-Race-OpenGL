#define _CRT_SECURE_NO_WARNINGS
#include "InitGame.h"
#include "GL/freeglut.h"
#include <windows.h>

void draw();
int main(int argc, char **argv)
{
	InitGame(argc, argv);
	glutDisplayFunc(draw);
	
	
	glutMainLoop();
}
void draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*glBegin(GL_TRIANGLES);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glEnd();*/
	glRotatef(180, 0, 1, 0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glmDraw(car, GLM_SMOOTH | GLM_TEXTURE);
	glutSwapBuffers();
}
